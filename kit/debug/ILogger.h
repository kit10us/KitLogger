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
#include <kit/debug/IBlock.h>
#include <string>
#include <memory>

namespace kit::debug
{
	/// <summary>
	/// Performs logging tasks.
	/// </summary>
	class ILogger
	{
	public:
		typedef std::shared_ptr< ILogger > ptr;

		virtual ~ILogger() {}

		/// <summary> 
		/// Attach a log listener.
		/// </summary>
		virtual void AttachListener( ILogListener::ptr logListener ) = 0;

		/// <summary> 
		/// Attach a log listener.
		/// </summary>
		virtual void DetachListener( ILogListener::ptr logListener ) = 0;

		/// <summary>
		/// Returns a list of loggers.
		/// </summary>
		virtual std::list<kit::debug::ILogListener::ptr> GetListeners() = 0;

		/// <summary>
		/// Log a line of text.
		/// </summary>
		virtual void Log(std::string text, std::string category = {}, std::string location = {}) = 0;

		/// <summary>
		/// Creates a debug block. It's main purpose is to
		/// allow the allocation of custom blocks while
		/// preserving a standard interface.
		/// </summary>
		virtual IBlock::ptr CreateBlock( std::string name ) = 0;
	};
}