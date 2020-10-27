#include "afxwin.h"
#include "iostream"
#include "ctime"
#include "windows.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    HWND hwnd = FindWindow("UnrealWindow", "Приложение Epic Games");
    if (hwnd != NULL) {
        char str_char[100];
        GetWindowText(hwnd, str_char, 100);
        cout << str_char << endl;
        time_t t_1 = time(0);
        time_t t_2 = time(0);

        //делает окно неюзабельным для пользователя
        EnableWindow(hwnd, false);

        //t_2 - t_1 < ... время на загрузку лаунчера
        do
        {
            hwnd = FindWindow("UnrealWindow", "Приложение Epic Games");
            if (hwnd != NULL)
            {
                t_2 = time(0);
            }
            else
            {
                return 0;
            }
        } while (t_2 - t_1 < 10);

        //3 таба 1 пробел для перехода на авторизацию по акку эпиков
        PostMessage(hwnd, WM_KEYDOWN, 9, 0);
        PostMessage(hwnd, WM_KEYUP, 9, 0);
        PostMessage(hwnd, WM_KEYDOWN, 9, 0);
        PostMessage(hwnd, WM_KEYUP, 9, 0);
        PostMessage(hwnd, WM_KEYDOWN, 9, 0);
        PostMessage(hwnd, WM_KEYUP, 9, 0);
        PostMessage(hwnd, WM_KEYDOWN, 32, 0);
        PostMessage(hwnd, WM_KEYUP, 32, 0);
        //слипы нужны для корректной работы табов
        Sleep(1000);

        //PostMessage(hwnd, WM_CHAR, VK_TAB, 0);
        //переход в строку логина
        PostMessage(hwnd, WM_KEYDOWN, 9, 0);
        PostMessage(hwnd, WM_KEYUP, 9, 0);



        char login[100] = "log";
        char pass[100] = "pass";
        //отправка логина через массив символов
        for (char c : login)
        {
            PostMessage(hwnd, WM_CHAR, c, 0);
        }
        Sleep(1000);
        //переход на пароль
        PostMessage(hwnd, WM_KEYDOWN, 9, 0);
        PostMessage(hwnd, WM_KEYUP, 9, 0);

        //в пароле создаются лишние табы, поэтому идет backspace для очистки
        Sleep(1000);
        PostMessage(hwnd, WM_KEYDOWN, 8, 0);
        PostMessage(hwnd, WM_KEYUP, 8, 0);
        PostMessage(hwnd, WM_KEYDOWN, 8, 0);
        PostMessage(hwnd, WM_KEYUP, 8, 0);
        Sleep(1000);

        //отправка пароля через массив символов
        for (char c : pass)
        {
            PostMessage(hwnd, WM_CHAR, c, 0);
        }
        //делаю окно юзабельным для пользователя
        EnableWindow(hwnd, true);
    }
        //получение имени хоста
        char buffer[256];
        unsigned long size = 256;

        GetComputerName(buffer, &size);

        printf("%s\n", buffer);
    
    STARTUPINFO cif;
    ZeroMemory(&cif, sizeof(STARTUPINFO));
    PROCESS_INFORMATION pi;
    if (CreateProcess("E:\\Program Files (x86)\\Steam\\Steam.exe", (LPSTR)" -login log pass", NULL, NULL, FALSE, NULL, NULL, NULL, &cif, &pi) == TRUE) 
    {
        cout << TRUE << endl;
    }

    return 0;
}