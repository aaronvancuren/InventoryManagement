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
        {"BRONZE", PowerSupplyCertification::Bronze},
        {"SILVER", PowerSupplyCertification::Silver},
        {"GOLD", PowerSupplyCertification::Gold},
        {"PLATINUM", PowerSupplyCertification::Platinum},
        {"TITANIUM", PowerSupplyCertification::Titanium}
    };
}
