#pragma once
#include <algorithm>
#include <map>
#include <string>

namespace StorageDevice
{
    enum class StorageDevice
    {
        NOSTORAGEDEVICE,
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
        {"Solid State Drive", StorageDevice::SSD},
        {"Hard Disk Drive", StorageDevice::HDD}
    };
}
