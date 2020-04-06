// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

#pragma once

#include <kit/LogEvent.h>
#include <string>
#include <memory>

namespace kit
{
	// Forward declarations...
	class ILogger;

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
	};
}