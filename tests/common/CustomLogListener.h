// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

#pragma once

#include <kit/debug/ILogListener.h>
#include <vector>

class CustomLogListener : public kit::debug::ILogListener
{
    std::vector< std::string > m_expectedLogText;
    int m_currentEventCounter;
public:
    CustomLogListener();
    ~CustomLogListener();

    void LogEvent( const kit::debug::LogEvent* event ) override;
};

