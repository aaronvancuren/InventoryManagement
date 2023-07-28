#pragma once
#include <algorithm>
#include <map>
#include <string>

namespace StorageDevice
{
    enum class StorageDevice
    {
        SSD,
        HDD
    };

    std::map<StorageDevice, std::string> const toStringMapping =
    {
        {StorageDevice::SSD, "Solid State Drive"},
        {StorageDevice::HDD, "Hard Disk Drive"}
    };

    std::map<std::string, StorageDevice> const toEnumMapping =
    {
        {"SOLID STATE DRIVE", StorageDevice::SSD},
        {"HARD DISK DRIVE", StorageDevice::HDD}
    };
}
