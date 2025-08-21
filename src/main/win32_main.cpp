#include <Windows.h>
#include <iostream>
#include <winuser.h>
#include <platform/public/platform.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    MessageBox(nullptr, "Hello World!", "Marie", MB_OK);
    
    marie::Window window;
    window.createWindow(800, 600, "Marie");
    window.show();
    window.setCurrent();
    
    while (!window.shouldClose())
    {
        //window.pollEvents();

        if (marie::isKeyDown(marie::KeyCode::A))
        {
            std::cout << "A" << std::endl; // I hate you sooo much!
        }
    }

    return 0;
}