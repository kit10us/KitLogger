// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

#include "CustomLogger.h"
#include "CustomBlock.h"

using namespace common;

CustomLogger::~CustomLogger()
{
}

void CustomLogger::AttachListener( kit::debug::ILogListener::ptr listener )
{
    m_listeners.push_back( listener );
    const auto event{ kit::debug::LogEvent{ "LOG LISTENER ATTACHED" } };
    listener->LogEvent( &event );
}

void CustomLogger::DetachListener( kit::debug::ILogListener::ptr listener )
{
    const auto event{ kit::debug::LogEvent{ "LOG LISTENER DETACHED" } };
    listener->LogEvent( &event );
    m_listeners.remove( listener );
}

void CustomLogger::Log( std::string text )
{
    const auto event{ kit::debug::LogEvent{ text } };
    for ( auto listener : m_listeners )
    {
        listener->LogEvent( &event );
    }
}

kit::debug::IBlock::ptr CustomLogger::CreateBlock( std::string name )
{
    return kit::debug::IBlock::ptr( new CustomBlock( this, name ) );
}
