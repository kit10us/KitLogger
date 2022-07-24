// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

#pragma once

#include <functional>
#include <memory>
#include <string>

namespace kit::debug
{
	/// <summary>
	/// Represents a block of code's lifetime for logging.
	/// We would create a shared_ptr (IBlock::ptr) to one of these so that
	/// we can either automatically popthese off the stack when
	/// we exit the block of code, or manually release the ptr.
	/// This signifies that all logging is relative to the block
	/// of code until the shared_ptr is released.
	/// </summary>
	class IBlock
	{
	public:
		typedef std::shared_ptr< IBlock > ptr;

		virtual ~IBlock() {};

		/// <summary>
		/// Sets our parent Custom Block.
		/// </summary>
		virtual void SetParent( IBlock* parent ) = 0;

		/// <summary>
		/// Gets the name of this block.
		/// </summary>
		virtual std::string GetName() const = 0;

		/// <summary>
		/// Log a line in this block.
		/// </summary>
		virtual void Log(std::string text, std::string catagory = {}) = 0;


		/// <summary>
		/// Creates a sub-block to this block.
		/// </summary>
		virtual IBlock::ptr SubBlock( std::string name ) = 0;

		/// <summary>
		/// Execute a functor wrapper in this block.
		/// </summary>
		virtual void Exec( std::function< void( IBlock* ) > function, bool timed = false ) = 0;			
	};
}