#pragma once
#include <algorithm>
#include <map>
#include <string>

namespace ScreenType
{
    enum class ScreenType
    {
        NOSCREEN,
        Flat,
        Curved
    };

    std::map<ScreenType, std::string> const toStringMapping =
    {
        {ScreenType::Flat, "Flat"},
        {ScreenType::Curved, "Curved"}
    };

    std::map<std::string, ScreenType> const toEnumMapping =
    {
        {"Flat", ScreenType::Flat},
        {"Curved", ScreenType::Curved}
    };
}
