// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

#pragma once

#include <string>

namespace kit
{
	/// <summary>
	/// Listens to log events.
	/// </summary>
	class ILogListener
	{
	public:
		virtual ~ILogListener() {}

		/// <summary>
		/// Event trigger when a log event happens.
		/// </summary>
		virtual void LogEvent( std::string text ) = 0;
	};
}