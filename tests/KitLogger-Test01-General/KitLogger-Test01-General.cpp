// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

#include <kit/ILogger.h>
#include <kit/ILogListener.h>
#include <kit/Block.h>
#include <list>
#include <iostream>

class CustomLogger : public kit::ILogger
{
    std::list<kit::Block*> m_blocks;
    std::list<kit::ILogListener*> m_listeners;

public:
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
public:
    MyLogListener()
    {
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

    CustomLogger logger;
    {
        Block outer( &logger, "Outer Block." );
        outer.Log( "Root" );
        {
            Block inner( &logger, "Inner Block." );
            inner.Log( "Sub" );
        }
    }
    
    cout << "Test Complete." << endl;
}
