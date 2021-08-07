#include <Windows.h>
#include <sstream>
#include "WindowsMessageMap.h"
#include "Window.h"

int CALLBACK 
WinMain(
    HINSTANCE hInstance, 
    HINSTANCE hPrevInstance,
    PSTR lpCmdLine, int nCmdShow)
{
    try
    {
        Window wnd(600, 400, "DirectX11 Tutorial");

        // message pump
        MSG msg;
        BOOL gResult;
        while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
        {
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
            while (!wnd.mouse.IsEmpty())
            {
                const auto e = wnd.mouse.Read();
                switch (e.GetType())
                {
                case Mouse::Event::Type::Leave:
                    wnd.SetTitle("Gone!");
                    break;
                case Mouse::Event::Type::Move:
                {
                    std::ostringstream oss;
                    oss << "Mouse moved to (" << e.GetPosX() << "," << e.GetPosY() << ")";
                    wnd.SetTitle(oss.str());
                }
                }
            }
        }

        if (gResult == -1)
        {
            return -1;
        }
        else
        {
            return msg.wParam;
        }
    }
    catch (const baseException& e)
    {
        MessageBoxA(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
    }
    catch (const std::exception& e)
    {
        MessageBoxA(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
    }
    catch (...)
    {
        MessageBoxA(nullptr, "No details available", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
    }
    return -1;
}