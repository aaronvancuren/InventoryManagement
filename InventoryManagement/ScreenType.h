#pragma once
#include <algorithm>
#include <map>
#include <string>

namespace ScreenType
{
    enum class ScreenType
    {
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
        {"FLAT", ScreenType::Flat},
        {"CURVED", ScreenType::Curved}
    };
}
