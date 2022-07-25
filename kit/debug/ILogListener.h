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

#include <kit/debug/LogEvent.h>
#include <unify/Path.h>
#include <memory>

namespace kit::debug
{
	/// <summary>
	/// Listens to log events.
	/// </summary>
	class ILogListener
	{
	public:
		typedef std::shared_ptr< ILogListener > ptr;

		virtual ~ILogListener() {}

		/// <summary>
		/// Event trigger when a log event happens.
		/// </summary>
		virtual void LogEvent( const LogEvent* event ) = 0;

		/// <summary>
		/// Returns the path to the log listener.
		/// This is how the listener is accessible outside of the app.
		/// This is empty if there is no way to access the log outside.
		/// </summary>
		virtual unify::Path GetPath() const = 0;
	};
}