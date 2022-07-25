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

#pragma once

#include <kit/debug/ILogListener.h>
#include <vector>

class CustomLogListener : public kit::debug::ILogListener
{
    std::vector< std::string > m_expectedLogText;
    int m_currentEventCounter;
public:
    CustomLogListener();
    ~CustomLogListener();

    void LogEvent( const kit::debug::LogEvent* event ) override;
    unify::Path GetPath() const override;
};

