//#include "stdafx.h"
#include "windows.h"
#include "iostream"
#include "ctime"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    HWND hwnd = FindWindow("UnrealWindow", "Приложение Epic Games");
    char str_char[100];
    GetWindowText(hwnd, str_char, 100);
    cout << str_char << endl;
    time_t t_1 = time(0);
    time_t t_2 = time(0);
    
    do
    { 
        hwnd = FindWindow("UnrealWindow", "Приложение Epic Games");
        if (hwnd != NULL) {
            char str_char[100];
            GetWindowText(hwnd, str_char, 100);
            ShowWindow(hwnd, SW_HIDE);
            t_2 = time(0);
        }
        else 
        {
            return 0;
        }
    } while (t_2 - t_1 < 10);
    
    PostMessage(hwnd, WM_KEYDOWN, 9, 0);
    PostMessage(hwnd, WM_KEYUP, 9, 0);
    PostMessage(hwnd, WM_KEYDOWN, 9, 0);
    PostMessage(hwnd, WM_KEYUP, 9, 0);
    PostMessage(hwnd, WM_KEYDOWN, 9, 0);
    PostMessage(hwnd, WM_KEYUP, 9, 0);
    PostMessage(hwnd, WM_KEYDOWN, 32, 0);
    PostMessage(hwnd, WM_KEYUP, 32, 0);
    
    Sleep(1000);

    //PostMessage(hwnd, WM_CHAR, VK_TAB, 0);
    PostMessage(hwnd, WM_KEYDOWN, 9, 0);
    PostMessage(hwnd, WM_KEYUP, 9, 0);

    Sleep(1000);

    char login[100] = "log";
    char pass[100] = "pass";

    for (char c : login) 
    {
        PostMessage(hwnd, WM_CHAR, c, 0);
    }    
    Sleep(1000);

    PostMessage(hwnd, WM_KEYDOWN, 9, 0);
    PostMessage(hwnd, WM_KEYUP, 9, 0);
 
    Sleep(1000);
    PostMessage(hwnd, WM_KEYDOWN, 8, 0);
    PostMessage(hwnd, WM_KEYUP, 8, 0);
    PostMessage(hwnd, WM_KEYDOWN, 8, 0);
    PostMessage(hwnd, WM_KEYUP, 8, 0);
    Sleep(1000);
    for (char c : pass)
    {
        PostMessage(hwnd, WM_CHAR, c, 0);
    }
    ShowWindow(hwnd, SW_SHOW);
    return 0;
}
