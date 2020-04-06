// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

#pragma once

#include <kit/IBlock.h>
#include <kit/LogEvent.h>
#include <kit/ILogListener.h>
#include <functional>
#include <iostream>
#include <string>
#include <memory>

namespace kit
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
		/// Create/allocate a block.
		/// </summary>
		virtual IBlock::ptr MakeBlock( std::string name ) = 0;

		/// <summary>
		/// Push a block onto the logger. It does not manage (new) the block
		/// </summary>
		virtual void PushBlock( IBlock* block ) = 0;

		/// <summary>
		/// Pop a block off of the logger. It does not manage (delete) the block.
		/// </summary>
		virtual void PopBlock( IBlock* block ) = 0;

		/// <summary>
		/// Log a line of text from a block.
		/// </summary>
		virtual void BlockLog( std::string text ) = 0;

		/// <summary>
		/// Get the block stack as text.
		/// </summary>
		virtual std::string GetBlockText() const = 0;

		/// <summary>
		/// Execute a function from within a block.
		/// </summary>
		void Block( std::string name, std::function< void(IBlock*)> functionBlock )
		{
			auto block = this->MakeBlock( name );

			// Pass as a pointer as to not increment use count.
			functionBlock( block.get() );
		}
	};
}