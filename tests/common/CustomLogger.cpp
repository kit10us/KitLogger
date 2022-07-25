/*
 * Kitlogger Interface
 * https://github.com/kit10us/unify
 * Copyright (c) 2020, Kit10 Studios LLC
 *
 * This file is part of Kitlogger Interface (a.k.a. KitLogger)
 *
 * Unify is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Unify is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Unify.  If not, see <https://www.gnu.org/licenses/>.
 */

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

std::list<kit::debug::ILogListener::ptr> CustomLogger::GetListeners()
{
    return m_listeners;
}

void CustomLogger::Log( std::string text, std::string category, std::string location)
{
    const auto event{ kit::debug::LogEvent{ text } };
    for ( auto listener : m_listeners )
    {
        listener->LogEvent( &event );
    }
}

kit::debug::IBlock::ptr CustomLogger::CreateBlock( std::string name )
{
    return kit::debug::IBlock::ptr( std::make_shared<CustomBlock>( this, name ) );
}
