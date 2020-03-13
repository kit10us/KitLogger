// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

#pragma once

#include <kit/Block.h>
#include <iostream>
#include <memory>

namespace kit
{
	// Forward declarations...
	class ILogListener;

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
		virtual void AttachListener( ILogListener* logListener ) = 0;

		/// <summary> 
		/// Attach a log listener.
		/// </summary>
		virtual void DetachListener( ILogListener* logListener ) = 0;

		/// <summary>
		/// Log a line of text.
		/// </summary>
		virtual void Log( std::string text ) = 0;

		/// <summary>
		/// Push a block onto the logger.
		/// </summary>
		virtual void PushBlock( kit::Block* block ) = 0;

		/// <summary>
		/// Pop a block off of the logger.
		/// </summary>
		virtual void PopBlock( kit::Block* block ) = 0;
	};
}