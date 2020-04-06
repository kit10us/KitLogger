// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

#include "BlockPopper.h"
#include <kit/ILogger.h>
#include <kit/ILogListener.h>
#include <kit/IBlock.h>
#include <list>
#include <iostream>
#include <vector>

class CustomBlock : public kit::IBlock
{
    kit::ILogger* m_logger;
    std::string m_name;
public:
    CustomBlock( kit::ILogger* logger, std::string name )
        : m_logger{ logger }
        , m_name{ name }
    {
        std::cout << "new Block \"" << m_name << "\"" << std::endl;
    }

    ~CustomBlock() override
    {
        std::cout << "delete Block \"" << m_name << "\"" << std::endl;
    }

    std::string GetName() const override
    {
        return m_name;
    }

    void Log( std::string text ) override
    {
        m_logger->Log( text );
    }
};


class CustomLogger : public kit::ILogger
{
    std::list<kit::ILogListener::ptr> m_listeners;
    std::list<kit::IBlock*> m_blocks;

public:
    ~CustomLogger()
    {
        if ( m_blocks.empty() )
        {
            std::cout << "All blocks have been popped." << std::endl;
        }
        else
        {
            std::cout << "Some blocks haven't been popped:" << std::endl;
            for ( auto block : m_blocks )
            {
                std::cout << "    " << block->GetName() << std::endl;
                delete block;
            }
        }
    }

    void AttachListener( kit::ILogListener::ptr listener ) override
    {
        m_listeners.push_back( listener );
        const auto event{ kit::LogEvent{ "LOG LISTENER ATTACHED" } };
        listener->LogEvent( &event );
    }

    void DetachListener( kit::ILogListener::ptr listener ) override
    {
        const auto event{ kit::LogEvent{ "LOG LISTENER DETACHED" } };
        listener->LogEvent( &event );
        m_listeners.remove( listener );
    }

    void Log( std::string text ) override
    {
        const auto event{ kit::LogEvent{ text } };
        for (auto listener : m_listeners )
        {
            listener->LogEvent( &event );
        }
    }

    void PushBlock( kit::IBlock* block ) override
    {
        m_blocks.push_back( block );
        std::cout << "Pushed \"" << block->GetName() << "\"" << std::endl;
    }

    void PopBlock( kit::IBlock* block ) override
    {
        std::cout << "Popped \"" << block->GetName() << "\"" << std::endl;
        delete block;
        m_blocks.remove( block );
    }

    kit::IBlock::ptr MakeBlock( std::string name ) override
    {
        kit::IBlock::ptr block( new CustomBlock( this, name ), kit::BlockPopper( this ) );
        PushBlock( block.get() );
        return block;
    }

    void BlockLog( std::string text ) override
    {
        std::cout << "[" << GetBlockText() << "] " << text << std::endl;
    }

    std::string GetBlockText() const override
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
    std::vector< std::string > m_expectedLogText;
    int m_currentEventCounter;
public:
    MyLogListener()
        : m_expectedLogText{
            "LOG LISTENER ATTACHED",
            "Log from the outer block.",
            "Log from the inner block.",
            "Log from the logger function block",
        }
        , m_currentEventCounter{}
    {

    }

    ~MyLogListener()
    {
    }

    void LogEvent( const kit::LogEvent* event ) override
    {
        if ( event->text != m_expectedLogText[m_currentEventCounter] )
        {
            throw std::exception( std::string( "Log event mismatch! Expected \"" + m_expectedLogText[m_currentEventCounter] + ", but got \"" + event->text + "\"." ).c_str() );
        }
        else
        {
            m_currentEventCounter++;

            std::cout << "Correct output: " << ((event->text + "\n").c_str()) << std::endl;
        }
    }
};


int main()
{
    using namespace std;
    try
    {
        using namespace kit;

        // Create the logger first, before any other logger constructs.
        CustomLogger logger;

        // Create the log listener; construct will automatically attach listener, in this case.

        logger.AttachListener( ILogListener::ptr{ new MyLogListener() } );

        // Manually create a block.
        {
            auto outer{ logger.MakeBlock( "Outer block." ) };
            outer->Log( "Log from the outer block." );

            // Manually create a second block.
            {
                auto inner{ logger.MakeBlock( "Inner block." ) };
                inner->Log( "Log from the inner block." );
            }
        }

        // Execute a lambda block.
        logger.Block( "Lambda block", []( kit::IBlock* block )
            {
                block->Log( "Log from the logger function block" );
            }
        );
        cout << "Test Complete." << endl;
    }
    catch ( std::exception ex )
    {
        cout << "Exception: " << ex.what() << endl;
    }
}
