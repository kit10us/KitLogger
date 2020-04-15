// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

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
		/// Log a line of text.
		/// </summary>
		virtual void Log( std::string text ) = 0;

		/// <summary>
		/// Creates a debug block. It's main purpose is to
		/// allow the allocation of custom blocks while
		/// preserving a standard interface.
		/// </summary>
		virtual IBlock::ptr CreateBlock( std::string name ) = 0;
	};
}