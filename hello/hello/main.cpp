#ifndef UNICODE
#define UNICODE
#endif 
#define ID_EDITCHILD 100
#include <windows.h>
#include <CommCtrl.h>
#include <stdlib.h> 
#include <string>
#include <wchar.h>
#include <sstream>
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[]  = L"Sample Window Class";
    
    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW/*WS_OVERLAPPED/*| WS_THICKFRAME | WS_SYSMENU*/,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 200,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
        );

    if (hwnd == NULL)
    {
        return 0;
    }
	/*
	LONG style = ::GetWindowLong(hwnd, GWL_EXSTYLE);
			style &= ~WS_EX_APPWINDOW;
			::SetWindowLong(hwnd, GWL_EXSTYLE, style);
    */
	ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

/*
BOOL Create(
        PCWSTR lpWindowName,
        DWORD dwStyle,
        DWORD dwExStyle = 0,
        int x = CW_USEDEFAULT,
        int y = CW_USEDEFAULT,
        int nWidth = CW_USEDEFAULT,
        int nHeight = CW_USEDEFAULT,
        HWND hWndParent = 0,
        HMENU hMenu = 0
        )
    {
        WNDCLASS wc = {0};

        wc.lpfnWndProc   = DERIVED_TYPE::WindowProc;
        wc.hInstance     = GetModuleHandle(NULL);
        wc.lpszClassName = ClassName();

        RegisterClass(&wc);

        m_hwnd = CreateWindowEx(
            dwExStyle, ClassName(), lpWindowName, dwStyle, x, y,
            nWidth, nHeight, hWndParent, hMenu, GetModuleHandle(NULL), this
            );

        return (m_hwnd ? TRUE : FALSE);
    }


*/
void OnSize(HWND hwnd, UINT flag, int width, int height)
{
    // Handle resizing
}
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  static HWND hwndEdit; 
 
    TCHAR lpszLatin[] =  L"Lor";
 
    
    switch (uMsg)
    {
      case WM_CREATE: 
        //MessageBox(NULL, L"ww", L"File Path", MB_OK);
        
        /*
            hwndEdit = CreateWindow( L"edit", L"",
WS_VISIBLE|WS_CHILD|WS_BORDER|WS_VSCROLL|WS_HSCROLL|

ES_MULTILINE|ES_WANTRETURN|ES_AUTOHSCROLL|ES_AUTOVSCROLL,

0, 0, 300, 200, hwnd, (HMENU)100, (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE), NULL);

 */
        hwndEdit = CreateWindowEx(
                                0, L"EDIT",   // predefined class 
                                NULL,         // no window title 
                                WS_CHILD | WS_VISIBLE | WS_VSCROLL | 
                                ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL, 
                                0, 0, 300, 200,   // set size in WM_SIZE message 
                                hwnd,         // parent window 
                                (HMENU) ID_EDITCHILD,   // edit control ID 
                                (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE), 
                                NULL);        // pointer not needed 
            // Add text to the window. 
            SendMessage(hwndEdit, WM_SETTEXT, 0, (LPARAM) lpszLatin); 
 
            return 0; 
 /*
        case WM_COMMAND: 
            switch (wParam) 
            { 
                case IDM_EDUNDO: 
                    // Send WM_UNDO only if there is something to be undone. 
 
                    if (SendMessage(hwndEdit, EM_CANUNDO, 0, 0)) 
                        SendMessage(hwndEdit, WM_UNDO, 0, 0); 
                    else 
                    {
                        MessageBox(hwndEdit, 
                                   L"Nothing to undo.", 
                                   L"Undo notification", 
                                   MB_OK); 
                    }
                    break; 
 
                case IDM_EDCUT: 
                    SendMessage(hwndEdit, WM_CUT, 0, 0); 
                    break; 
 
                case IDM_EDCOPY: 
                    SendMessage(hwndEdit, WM_COPY, 0, 0); 
                    break; 
 
                case IDM_EDPASTE: 
                    SendMessage(hwndEdit, WM_PASTE, 0, 0); 
                    break; 
 
                case IDM_EDDEL: 
                    SendMessage(hwndEdit, WM_CLEAR, 0, 0); 
                    break; 

                case IDM_ABOUT: 
                    DialogBox(hInst,                // current instance 
                              L"AboutBox",           // resource to use 
                              hwnd,                 // parent handle 
                              (DLGPROC) About); 
                    break; 

                default: 
                    return DefWindowProc(hwnd, message, wParam, lParam); 
            } 
            break;
       */
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
   case WM_SIZE: 
        {
            int width = LOWORD(lParam);  // Macro to get the low-order word.
            int height = HIWORD(lParam); // Macro to get the high-order word.
            /*
            std::wstringstream wss;
            wss << "width:" << width <<"  height:" << height;
            SendMessage(hwndEdit, WM_SETTEXT, 0, (LPARAM) wss.str().c_str()); 
            */
            // Respond to the message:
            OnSize(hwnd, (UINT)wParam, width, height);
        }
        break;
        
   case WM_SIZING:
     {
       RECT* po = (RECT*)(lParam);
       std::wstringstream wss;
       po->left = 10;
       wss << "right:" << po->right <<"  left:" << po->left;
            SendMessage(hwndEdit, WM_SETTEXT, 0, (LPARAM) wss.str().c_str()); 
     }
     break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
        return 0;
	case WM_LBUTTONDOWN:
		{
      WINDOWINFO infoa;
      std::wstringstream wss;
      /*
  GetWindowInfo(hwnd, &infoa);
  wss << "window height:" << infoa.rcWindow.bottom - infoa.rcWindow.top;
  wss << "window width:" << infoa.rcWindow.right - infoa.rcWindow.left;
  wss << "client height:" << infoa.rcClient.bottom - infoa.rcClient.top;
  wss << "client width:" << infoa.rcClient.right - infoa.rcClient.left;
  wss << "boders x:" << infoa.cxWindowBorders;
  wss << "boders y:" << infoa.cyWindowBorders;

  wss << "Width of screen:" << GetSystemMetrics(SM_CXSCREEN);
  wss << "Height of screen:" << GetSystemMetrics(SM_CYSCREEN);
  wss << "Width of window frame that can be sized:" << GetSystemMetrics(SM_CXFRAME);
  wss << "Height of window frame that can be sized:" << GetSystemMetrics(SM_CYFRAME);
  wss << "Width of window frame that cannot be sized" << GetSystemMetrics(SM_CXBORDER);
  wss << "Height of window frame that cannot be sized" << GetSystemMetrics(SM_CYBORDER);
  */wss << "SM_CYMAXIMIZED" << GetSystemMetrics(SM_CXMAXTRACK);
  RECT desktop;
   // Get a handle to the desktop window
   const HWND hDesktop = GetDesktopWindow();
   // Get the size of screen to the variable desktop
   GetClientRect(hDesktop, &desktop);
   wss << "left:" << desktop.left << ",right:" << desktop.right << ",top: " << desktop.top << ",bottom:" <<desktop.bottom;
   GetWindowRect(hwnd, &desktop);
   wss << "left:" << desktop.left << ",right:" << desktop.right << ",top: " << desktop.top << ",bottom:" <<desktop.bottom;
      SendMessage(hwndEdit, WM_SETTEXT, 0, (LPARAM) wss.str().c_str());
         //SendMessage(hwnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
        //SetWindowPos(hwnd, NULL, 0, 0, 800, 600, SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOMOVE);    
        //
			//ShowWindow(hwnd, SW_MAXIMIZE);
      //SetWindowPos(hwnd, HWND_TOP, 0, 0, 100, 100, SWP_NOSIZE | SWP_NOMOVE);
			//MessageBox(NULL, L"ww", L"File Path", MB_OK);
			//ShowWindow(hwnd, SW_HIDE);
			//LONG style = GetWindowLong(hwnd, GWL_EXSTYLE);
			//style &= ~WS_EX_APPWINDOW;
			//style &= WS_EX_TOOLWINDOW ;
			//SetWindowLong(hwnd, GWL_EXSTYLE, WS_EX_TOOLWINDOW);
			//ShowWindow(hwnd, SW_SHOW);
			return 0;
		}

    if (hwnd == NULL)
    {
        return 0;
    }


    }
	
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

