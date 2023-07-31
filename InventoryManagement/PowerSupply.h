#pragma once
#include "EnumHelpers.h"
#include "Product.h"
#include "PowerSupplyCertification.h"

class PowerSupply : public Product
{
private:
    int wattage;
    PowerSupplyCertification::PowerSupplyCertification powerSupplyCertification;
    bool fullyModular; // (True) Fully Modular or (False) Semi-Modular
public:
    PowerSupply(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const std::string& sku, const float& price,
        const int& wattage, const std::string& powerSupplyCertification, const bool& fullyModular)
        : Product(name, description, brand, model, sku, price)
    {
        this->wattage = wattage;
        this->powerSupplyCertification = getEnumType(PowerSupplyCertification::toEnumMapping, powerSupplyCertification);
        this->fullyModular = fullyModular;
    }

    PowerSupply(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const float& price,
        const int& wattage, const std::string& powerSupplyCertification, const bool& fullyModular)
        : Product(name, description, brand, model, price)
    {
        this->wattage = wattage;
        this->powerSupplyCertification = getEnumType(PowerSupplyCertification::toEnumMapping, powerSupplyCertification);
        this->fullyModular = fullyModular;
    }

    PowerSupply(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const float& price,
        const int& wattage, const PowerSupplyCertification::PowerSupplyCertification& powerSupplyCertification, const bool& fullyModular)
        : Product(name, description, brand, model, price)
    {
        this->wattage = wattage;
        this->powerSupplyCertification = powerSupplyCertification;
        this->fullyModular = fullyModular;
    }

    std::string toString() const override
    {
        return "some string";
    }
};
