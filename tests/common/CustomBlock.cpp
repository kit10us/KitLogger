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

#include <common/CustomBlock.h>
#include <iostream>

using namespace common;

CustomBlock::CustomBlock( kit::debug::ILogger* logger, std::string name )
    : m_parent{}
    , m_logger{ logger }
    , m_name{ name }
{
    std::cout << "new Block \"" << m_name << "\"" << std::endl;
}

CustomBlock::~CustomBlock()
{
    std::cout << "delete Block \"" << m_name << "\"" << std::endl;
}

void CustomBlock::SetParent( IBlock* parent )
{
    m_parent = parent;
}

std::string CustomBlock::GetName() const
{
    return (m_parent ? (m_parent->GetName() + "::") : "") + m_name;
}

void CustomBlock::Log( std::string text, std::string category)
{
    m_logger->Log( text, category);
}

kit::debug::IBlock::ptr CustomBlock::SubBlock( std::string name )
{
    auto block{ m_logger->CreateBlock( name ) };
    block->SetParent( this );
    return block;
}

void CustomBlock::Exec( std::function< void( IBlock* )> functionBlock, bool timed)
{
    functionBlock( this );
}

