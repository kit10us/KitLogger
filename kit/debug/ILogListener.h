// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

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