// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

// Only includes needed for added code in MainWindow:MainWindow()
#include <winrt/Microsoft.UI.Interop.h>
#include <Microsoft.UI.Xaml.Window.h>
#include <winrt/Microsoft.UI.Windowing.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::App1::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();

        // Get handle.
        auto windowNative{ this->try_as<::IWindowNative>() };
        winrt::check_bool(windowNative);
        HWND hWnd{ 0 };
        windowNative->get_WindowHandle(&hWnd);

        // Retrieve the WindowId that corresponds to hWnd.
        Microsoft::UI::WindowId windowId = Microsoft::UI::GetWindowIdFromWindow(hWnd);

        // Retrieve the AppWindow for the current (XAML) WinUI 3 window.
        Microsoft::UI::Windowing::AppWindow appWindow = Microsoft::UI::Windowing::AppWindow::GetFromWindowId(windowId); 

        // Titlebar full customization.
        this->ExtendsContentIntoTitleBar(true);
        this->SetTitleBar(AppTitleBar());
        
        // Set drag rectangle.
   /*     winrt::Windows::Graphics::RectInt32 rect[]{(0,0,1,1)};	
        auto titlebar = appWindow.TitleBar();
        titlebar.SetDragRectangles(rect);*/
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    //void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    //{
    // /*   myButton().Content(box_value(L"Clicked"));*/
    //}
}
