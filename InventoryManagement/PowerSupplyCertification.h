#pragma once
#include <algorithm>
#include <map>
#include <string>

namespace PowerSupplyCertification
{
    enum class PowerSupplyCertification
    {
        Bronze,
        Silver,
        Gold,
        Platinum,
        Titanium
    };

    std::map<PowerSupplyCertification, std::string> const toStringMapping =
    {
        {PowerSupplyCertification::Bronze, "Bronze"},
        {PowerSupplyCertification::Silver, "Silver"},
        {PowerSupplyCertification::Gold, "Gold"},
        {PowerSupplyCertification::Platinum, "Platinum"},
        {PowerSupplyCertification::Titanium, "Titanium"}
    };

    std::map<std::string, PowerSupplyCertification> const toEnumMapping =
    {
        {"Bronze", PowerSupplyCertification::Bronze},
        {"Silver", PowerSupplyCertification::Silver},
        {"Gold", PowerSupplyCertification::Gold},
        {"Platinum", PowerSupplyCertification::Platinum},
        {"Titanium", PowerSupplyCertification::Titanium}
    };
}
