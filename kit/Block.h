// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

#pragma once

#include <string>

namespace kit
{
	// Forward declarations.
	class ILogger;

	/// <summary>
	/// Used to create a debug block that auto pops, when we pop the strack frame.
	/// </summary>
	class Block
	{
		ILogger * m_logger;
		std::string m_name;

	public:
		Block( ILogger * debug, std::string name );
		~Block();

		/// <summary>
		/// Gets the name of this block.
		/// </summary>
		std::string GetName() const;

		/// <summary>
		/// Log a line in this block.
		/// Ultimately just a pass-through to the debugger logger.
		/// </summary>
		void Log( std::string line );
	};
}