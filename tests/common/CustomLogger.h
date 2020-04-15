// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

#pragma once

#include <kit/debug/ILogger.h>
#include <kit/debug/IBlock.h>
#include <list>
#include <memory>

namespace common
{
    class CustomBlock;

    class CustomLogger : public kit::debug::ILogger
    {
        std::list<kit::debug::ILogListener::ptr> m_listeners;
    public:
        ~CustomLogger();
        void AttachListener( kit::debug::ILogListener::ptr listener ) override;
        void DetachListener( kit::debug::ILogListener::ptr listener ) override;
        void Log( std::string text ) override;
        kit::debug::IBlock::ptr CreateBlock( std::string name ) override;
    };
}