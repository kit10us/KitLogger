// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

#pragma once

#include <memory>
#include <string>

namespace kit
{
	// Forward declarations.
	class ILogger;

	/// <summary>
	/// Used to create a debug block that auto pops, when we pop the strack frame.
	/// </summary>
	class IBlock
	{
		ILogger * m_logger;
		std::string m_name;

	public:
		typedef std::shared_ptr< IBlock > ptr;

		virtual ~IBlock() {};

		/// <summary>
		/// Gets the name of this block.
		/// </summary>
		virtual std::string GetName() const = 0;

		/// <summary>
		/// Log a line in this block.
		/// Ultimately just a pass-through to the debugger logger.
		/// </summary>
		virtual void Log( std::string line ) = 0;
	};
}