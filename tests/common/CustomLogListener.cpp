// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

#include "CustomLogListener.h"
#include <iostream>

CustomLogListener::CustomLogListener()
    : m_expectedLogText{
        "LOG LISTENER ATTACHED",
        "Log from the outer block.",
        "Log from the inner block.",
        "Log from the logger function block",
        "before first block",
        "inside first block, before second block",
        "inside second block",
        "inside first block, after second block",
        "after first block" 
    }
    , m_currentEventCounter{}
{
}

CustomLogListener::~CustomLogListener()
{
}

void CustomLogListener::LogEvent( const kit::debug::LogEvent* event )
{
    using namespace std;
    if ( event->text != m_expectedLogText[m_currentEventCounter] )
    {
        throw exception( string( "Log event mismatch! Expected \"" + m_expectedLogText[m_currentEventCounter] + "\", but got \"" + event->text + "\"." ).c_str() );
    }
    else
    {
        m_currentEventCounter++;

        cout << "Correct output: " << ((event->text + "\n").c_str()) << std::endl;
    }
}
