// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

#pragma once

#include <string>

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
		virtual ~ILogListener() {}

		/// <summary>
		/// Attach listener to logger.
		/// </summary>
		virtual void Attach( ILogger* logger ) = 0;

		/// <summary>
		/// Detach listener from logger.
		/// </summary>
		virtual void Detach() = 0;

		/// <summary>
		/// Event trigger when a log event happens.
		/// </summary>
		virtual void LogEvent( std::string text ) = 0;
	};
}