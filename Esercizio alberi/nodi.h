#pragma once

#include "nodi.g.h"

namespace winrt::Esercizioalberi::implementation
{
    struct nodi : nodiT<nodi>
    {
        nodi();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::Esercizioalberi::factory_implementation
{
    struct nodi : nodiT<nodi, implementation::nodi>
    {
    };
}
