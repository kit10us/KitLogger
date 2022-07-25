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

#include <kit/debug/ILogger.h>
#include <kit/debug/IBlock.h>
#include <list>
#include <memory>

namespace common
{
    class CustomBlock;

    class CustomLogger : public kit::debug::ILogger
    {
        std::list<kit::debug::ILogListener::ptr> m_listeners;
    public:
        ~CustomLogger();
        void AttachListener( kit::debug::ILogListener::ptr listener ) override;
        void DetachListener( kit::debug::ILogListener::ptr listener ) override;
        std::list<kit::debug::ILogListener::ptr> GetListeners() override;
        void Log( std::string text, std::string category = {}, std::string location = {}) override;
        kit::debug::IBlock::ptr CreateBlock( std::string name ) override;
    };
}