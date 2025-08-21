#pragma once

namespace marie
{
    class Window 
    {
    public: 
        Window();
        ~Window();
        
        void createWindow(int width, int height, const char* title);
        bool shouldClose();
        void pollEvents();
        void show();
    private:
        void* data;
    };
}