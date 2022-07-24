// Copyright (c) 2002 - 2018, Kit10 Studios LLC
// All Rights Reserved

#pragma once

#include <string>
#include <chrono>

namespace kit::debug
{
	/// <summary>
	/// Log event's argument structure.
	/// </summary>
	struct LogEvent
	{
		/// <summary>
		/// Text.
		/// </summary>
		std::string text;

		/// <summary>
		/// Time of event.
		/// </summary>
		std::chrono::system_clock::time_point time;

		/// <summary>
		/// User defined catagory.
		/// </summary>
		std::string catagory;

		/// <summary>
		/// User defined location.
		/// </summary>
		std::string location;
	};
}