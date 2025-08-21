#pragma once

#include <platform/public/platform.h>
#include <windows.h>

using namespace marie;

struct WindowProperties
{
    int width;
    int height;
    const char* title;
    bool shouldClose;
};

struct WindowData
{
    WNDCLASS wndClass;
    HWND hwnd;
    WindowProperties properties;

    void registerWndClass();
    void createHwnd();
    void processMessage();
};

extern Window* currentWindow;