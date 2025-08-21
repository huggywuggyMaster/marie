#pragma once

namespace marie
{
    enum class KeyCode
    {
    // Buchstaben
        A = 0x41,
        B = 0x42,
        C = 0x43,
        D = 0x44,
        E = 0x45,
        F = 0x46,
        G = 0x47,
        H = 0x48,
        I = 0x49,
        J = 0x4A,
        K = 0x4B,
        L = 0x4C,
        M = 0x4D,
        N = 0x4E,
        O = 0x4F,
        P = 0x50,
        Q = 0x51,
        R = 0x52,
        S = 0x53,
        T = 0x54,
        U = 0x55,
        V = 0x56,
        W = 0x57,
        X = 0x58,
        Y = 0x59,
        Z = 0x5A,

        // Zahlen oben auf der Tastatur
        KEY_0 = 0x30,
        KEY_1 = 0x31,
        KEY_2 = 0x32,
        KEY_3 = 0x33,
        KEY_4 = 0x34,
        KEY_5 = 0x35,
        KEY_6 = 0x36,
        KEY_7 = 0x37,
        KEY_8 = 0x38,
        KEY_9 = 0x39,

        // Steuer- und Funktionstasten
        SPACE = 0x20,
        ENTER = 0x0D,
        ESCAPE = 0x1B,
        LEFT = 0x25,
        UP = 0x26,
        RIGHT = 0x27,
        DOWN = 0x28,
        TAB = 0x09,
        BACKSPACE = 0x08,

        // F-Tasten
        F1 = 0x70,
        F2 = 0x71,
        F3 = 0x72,
        F4 = 0x73,
        F5 = 0x74,
        F6 = 0x75,
        F7 = 0x76,
        F8 = 0x77,
        F9 = 0x78,
        F10 = 0x79,
        F11 = 0x7A,
        F12 = 0x7B
    };

    class Window 
    {
    public: 
        Window();
        ~Window();
        
        void createWindow(int width, int height, const char* title);
        bool shouldClose();
        void pollEvents();
        void show();
        void setShouldClose(bool x);
        void setCurrent();
    private:
        void* data;
    };

    bool isKeyDown(KeyCode key);
    bool isKeyUp(KeyCode key);
}