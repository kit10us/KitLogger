// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

#include <kit/ILogger.h>
#include <kit/ILogListener.h>
#include <kit/Block.h>
#include <list>
#include <iostream>

class CustomLogger : public kit::ILogger
{
    std::list<kit::ILogListener*> m_listeners;
    std::list<kit::Block*> m_blocks;

public:
    void AttachListener( kit::ILogListener* logListener ) override
    {
        m_listeners.push_back( logListener );
        logListener->LogEvent( "LOG LISTENER ATTACHED" );
    }

    void DetachListener( kit::ILogListener* logListener ) override
    {
        logListener->LogEvent( "LOG LISTENER DETACHED" );
        m_listeners.remove( logListener );
    }

    void Log( std::string text ) override
    {
        for (auto listener : m_listeners )
        {
            listener->LogEvent( text );
        }
    }

    void PushBlock( kit::Block* block ) override
    {

        std::cout << GetBlocksText() << std::endl;
        std::cout << "Pushed " << block->GetName() << std::endl;
    }

    void PopBlock( kit::Block* block ) override
    {
        std::cout << "Popped " << block->GetName() << std::endl;
        std::cout << GetBlocksText() << std::endl;
    }

    std::string GetBlocksText() const
    {
        std::string text;
        for (auto block = m_blocks.begin(); block != m_blocks.end(); block++)
        {
            if (!text.empty())
            {
                text += "::";
            }
            text += (*block)->GetName();
        }

        return text;
    }
};


class MyLogListener : public kit::ILogListener
{
    kit::ILogger* m_logger;
public:
    MyLogListener( kit::ILogger* logger )
    {
        Attach( logger );
    }

    ~MyLogListener()
    {
        Detach();
    }

    void Attach( kit::ILogger* logger ) override
    {
        if( m_logger == nullptr )
        {
            logger->AttachListener( this );
            m_logger = logger;
        }
    }

    void Detach() override
    {
        if( m_logger )
        {
            m_logger->DetachListener( this );
            m_logger = {};
        }
    }

    void LogEvent( std::string text ) override
    {
        std::cout << ((text + "\n").c_str()) << std::endl;
    }
};


int main()
{
    using namespace std;
    using namespace kit;

    // Create the logger first, before any other logger constructs.
    CustomLogger logger;
    {
        // Create the log listener; construct will automatically attach listener, in this case.
        MyLogListener myLogListener( &logger );

        // Attempt 
        {
            Block outer( &logger, "Outer block." );
            outer.Log( "Log from the outer block." );
            {
                Block inner( &logger, "Inner block." );
                inner.Log( "Log from the inner block." );
            }
        }
    }
    
    cout << "Test Complete." << endl;
}
