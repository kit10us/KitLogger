// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

#pragma once

#include <kit/debug/IBlock.h>
#include <common/CustomLogger.h>
#include <string>

namespace common
{
    class CustomBlock : public kit::debug::IBlock
    {
        kit::debug::IBlock* m_parent;
        kit::debug::ILogger* m_logger;
        std::string m_name;
    public:
        CustomBlock( kit::debug::ILogger* logger, std::string name );
        ~CustomBlock() override;

        void SetParent( IBlock* parent ) override;
        std::string GetName() const override;
        void Log( std::string text ) override;
        kit::debug::IBlock::ptr SubBlock( std::string name ) override;
        void Exec( std::function< void( IBlock* )> functionBlock ) override;
    };
}