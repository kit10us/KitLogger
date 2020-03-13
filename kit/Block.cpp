// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

#pragma once

#include <kit/Block.h>
#include <kit/ILogger.h>

using namespace kit;

Block::Block( ILogger * logger, std::string name )
	: m_logger{ logger }
	, m_name{ name }
{
	m_logger->PushBlock( this );
}

Block::~Block()
{
	m_logger->PopBlock( this );
}

std::string Block::GetName() const
{
	return m_name;
}

void Block::Log( std::string line )
{
	m_logger->Log( line );
}
