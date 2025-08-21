#include "intern.h"
#include <assert/public/assert.h>
#include <winuser.h>

using namespace marie;

#define windowData static_cast<WindowData*>(data)

Window* currentWindow = nullptr;
static bool keys[512];

static LRESULT windowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
        case WM_KEYDOWN:
        {
            keys[wParam] = true;
            break;
        }

        case WM_KEYUP:
        case WM_SYSKEYUP:
        {
            MessageBox(nullptr, "", "", MB_HELP);
            keys[wParam] = false;
            break;
        }
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

Window::Window()
{
    this->data = new WindowData();
}

Window::~Window()
{
    delete windowData;
}

void Window::createWindow(int width, int height, const char* title)
{
    windowData->properties.width = width;
    windowData->properties.height = height;
    windowData->properties.shouldClose = false;
    windowData->properties.title = title;

    windowData->registerWndClass(); 
    windowData->createHwnd();   
}

bool Window::shouldClose()
{
    return windowData->properties.shouldClose;
}

void WindowData::registerWndClass()
{
    wndClass.lpszClassName = "MarieEngineWindow";
    wndClass.hInstance = GetModuleHandle(nullptr);
    wndClass.lpfnWndProc = windowProc;

    RegisterClass(&wndClass);
}

void Window::pollEvents()
{
    windowData->processMessage();
}

void Window::show()
{
    ShowWindow(windowData->hwnd, SW_SHOW);
}

void Window::setCurrent()
{
    currentWindow = this;
}

void Window::setShouldClose(bool x)
{
    windowData->properties.shouldClose = x;
}

void WindowData::createHwnd()
{
    RECT windowRect = {0, 0, properties.width, properties.height};
    AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, false);

    hwnd = CreateWindowEx(
        0,
        wndClass.lpszClassName,
        properties.title,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        windowRect.right - windowRect.left,
        windowRect.bottom - windowRect.top,
        nullptr,
        nullptr,
        wndClass.hInstance,
        nullptr
    );

    checkm(hwnd == nullptr, "Failed to create Window!");
}

void WindowData::processMessage()
{
    MSG msg = {0};
    while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
        {
            properties.shouldClose = true;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

bool marie::isKeyDown(KeyCode key)
{
    return keys[static_cast<int>(key)];
}

bool marie::isKeyUp(KeyCode key)
{
    return !keys[static_cast<int>(key)];
}