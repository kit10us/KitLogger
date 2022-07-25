/*
 * Kitlogger Interface
 * https://github.com/kit10us/unify
 * Copyright (c) 2020, Kit10 Studios LLC
 *
 * This file is part of Kitlogger Interface (a.k.a. KitLogger)
 *
 * Unify is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Unify is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Unify.  If not, see <https://www.gnu.org/licenses/>.
 */

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
		virtual void Log(std::string text, std::string category = {}) = 0;

		/// <summary>
		/// Creates a sub-block to this block.
		/// </summary>
		virtual IBlock::ptr SubBlock( std::string name ) = 0;

		/// <summary>
		/// Execute a functor wrapper in this block.
		/// </summary>
		/// <param name="function">Lambda to execute.</param>
		/// <param name="timed">True if we have a timout for the lambda.</param>
		virtual void Exec( std::function< void( IBlock* ) > function, bool timed = false ) = 0;			
	};
}