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

unify::Path CustomLogListener::GetPath() const
{
    return {};
}
