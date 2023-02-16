#pragma once

#include "passaggi.g.h"

namespace winrt::Minutilavorati::implementation
{
    struct passaggi : passaggiT<passaggi>
    {
        passaggi();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::Minutilavorati::factory_implementation
{
    struct passaggi : passaggiT<passaggi, implementation::passaggi>
    {
    };
}
