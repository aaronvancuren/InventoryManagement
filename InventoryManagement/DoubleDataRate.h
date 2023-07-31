#pragma once
#include <algorithm>
#include <map>
#include <string>

namespace DoubleDataRate
{
    enum class DoubleDataRate
    {
        INVALID,
        DDR,
        DDR2,
        DDR3,
        DDR4,
        DDR5
    };

    std::map<DoubleDataRate, std::string> const toStringMapping =
    {
        {DoubleDataRate::DDR, "DDR"},
        {DoubleDataRate::DDR2, "DDR2"},
        {DoubleDataRate::DDR3, "DDR3"},
        {DoubleDataRate::DDR4, "DDR4"},
        {DoubleDataRate::DDR5, "DDR5"}
    };

    std::map<std::string, DoubleDataRate> const toEnumMapping =
    {
        {"DDR", DoubleDataRate::DDR},
        {"DDR2", DoubleDataRate::DDR2},
        {"DDR3", DoubleDataRate::DDR3},
        {"DDR4", DoubleDataRate::DDR4},
        {"DDR5", DoubleDataRate::DDR5}
    };
}
