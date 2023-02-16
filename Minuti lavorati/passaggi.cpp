#include "pch.h"
#include "passaggi.h"
#if __has_include("passaggi.g.cpp")
#include "passaggi.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Minutilavorati::implementation
{
    passaggi::passaggi()
    {
        InitializeComponent();
    }

    int32_t passaggi::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void passaggi::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void passaggi::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
