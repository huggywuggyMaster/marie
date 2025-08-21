#include <Windows.h>
#include <winuser.h>
#include <platform/public/platform.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    MessageBox(nullptr, "Hello World!", "Marie", MB_OK);
    
    marie::Window window;
    window.createWindow(800, 600, "Marie");
    window.show();

    while (!window.shouldClose())
    {
        window.pollEvents();
    }

    return 0;
}