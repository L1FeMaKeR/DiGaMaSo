#include <Windows.h>

static bool globalRunning = true;

LRESULT CALLBACK WindowsCallback(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;

    
    switch (message)
    {
        case WM_CLOSE:
        {
            globalRunning = false;
        }break;
        case WM_DESTROY:
        {
            globalRunning = false;
        }break;
    
        default:
        {
            result = DefWindowProcA(window, message, wParam, lParam);
        }break;
    }

    return result;
}

int WinMain(HINSTANCE instance, HINSTANCE prevInstance, PSTR cmdLine, INT cmdShow)
{
    WNDCLASSA WindowClass = {};
    WindowClass.style = CS_HREDRAW | CS_VREDRAW;
    WindowClass.lpfnWndProc = WindowsCallback;
    WindowClass.hInstance = instance;
    WindowClass.hCursor = LoadCursor(0, IDC_ARROW);
    //WindowClass.hIcon = ;
    WindowClass.lpszClassName = "DiGaMaSoWindowClass";

    
    if (RegisterClassA(&WindowClass))
    {
        HWND Window = CreateWindowExA(0, WindowClass.lpszClassName, "DiGaMaSo", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, 0, 0, instance, 0);
        
        if (Window) 
        {
            
        }
        
    }
        

    return 0;
}