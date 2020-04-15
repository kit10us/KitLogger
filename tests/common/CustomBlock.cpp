// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

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

void CustomBlock::Log( std::string text )
{
    m_logger->Log( text );
}

kit::debug::IBlock::ptr CustomBlock::SubBlock( std::string name )
{
    auto block{ m_logger->CreateBlock( name ) };
    block->SetParent( this );
    return block;
}

void CustomBlock::Exec( std::function< void( IBlock* )> functionBlock )
{
    functionBlock( this );
}

