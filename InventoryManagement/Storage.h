#pragma once
#include "EnumHelpers.h"
#include "Product.h"
#include "StorageDevice.h"

class Storage : public Product
{
private:
    StorageDevice::StorageDevice storageDevice;
    bool internalComponent;
public:
    Storage(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const std::string& sku, const float& price,
        const std::string& storageDevice, const bool& internalComponent)
        : Product(name, description, brand, model, sku, price)
    {
        this->storageDevice = getEnumType(StorageDevice::toEnumMapping, storageDevice);
        this->internalComponent = internalComponent;
    }

    Storage(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const float& price,
        const std::string& storageDevice, const bool& internalComponent)
        : Product(name, description, brand, model, price)
    {
        this->storageDevice = getEnumType(StorageDevice::toEnumMapping, storageDevice);
        this->internalComponent = internalComponent;
    }

    Storage(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const float& price,
        const StorageDevice::StorageDevice& storageDevice, const bool& internalComponent)
        : Product(name, description, brand, model, price)
    {
        this->storageDevice = storageDevice;
        this->internalComponent = internalComponent;
    }

    std::string toString() const override
    {
        return "some string";
    }
};
