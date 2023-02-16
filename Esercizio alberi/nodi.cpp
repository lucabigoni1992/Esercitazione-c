#include "pch.h"
#include "nodi.h"
#if __has_include("nodi.g.cpp")
#include "nodi.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Esercizioalberi::implementation
{
    nodi::nodi()
    {
        InitializeComponent();
    }

    int32_t nodi::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void nodi::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void nodi::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
