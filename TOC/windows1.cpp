#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <windows.h>

LRESULT CALLBACK main_window_proc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            BeginPaint(hwnd, &ps);
            const HDC hdc = ps.hdc;

            // Here all your drawing codes go

            EndPaint(hwnd, &ps);
            break;
        }
        case WM_LBUTTONDOWN: {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);

            printf("clicked on %d, %d\n", x, y);

            break;
        }
        case WM_LBUTTONUP: {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);

            break;
        }
        case WM_MOUSEMOVE: {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);


            break;
        }
        case WM_SIZE: {
            RECT rect;
            GetClientRect(hwnd, &rect);
            break;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}

int main()
{
    const char window_class_name[] = "main_window_class";

    WNDCLASSEX wincl;
    HWND hwnd;

    wincl.hInstance = GetModuleHandle(0);
    wincl.lpszClassName = window_class_name;
    wincl.lpfnWndProc = main_window_proc;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);

    wincl.hIcon = LoadIcon(0, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon(0, IDI_APPLICATION);
    wincl.hCursor = LoadCursor(0, IDC_ARROW);
    wincl.lpszMenuName = 0;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    if (RegisterClassEx(&wincl)) {
        hwnd = CreateWindowEx(
                    0,
                    window_class_name,
                    "Hello Canvas!",
                    WS_OVERLAPPEDWINDOW,
                    CW_USEDEFAULT,
                    CW_USEDEFAULT,
                    1000,
                    600,
                    HWND_DESKTOP,
                    0,
                    wincl.hInstance,
                    0);
        ShowWindow(hwnd, SW_SHOW);
    }

    MSG messages;
    while (GetMessage(&messages, 0, 0, 0)) {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return 0;
}










