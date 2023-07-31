#pragma once
#include "DoubleDataRate.h"
#include "EnumHelpers.h"
#include "Product.h"

class Motherboard : public Product
{
private:
    float speed; // MHz
    DoubleDataRate::DoubleDataRate doubleDataRate;
    int numberOfRAMSlots;
    bool wifiEnabled;
    bool integratedGraphics;
public:
    Motherboard(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const std::string& sku, const float& price,
        const float& speed, const std::string& doubleDataRate, const int& numberOfRAMSlots, const bool& wifiEnabled, const bool& integratedGraphics)
        : Product(name, description, brand, model, sku, price)
    {
        this->speed = speed;
        this->doubleDataRate = getEnumType(DoubleDataRate::toEnumMapping, doubleDataRate);
        this->numberOfRAMSlots = numberOfRAMSlots;
        this->wifiEnabled = wifiEnabled;
        this->integratedGraphics = integratedGraphics;

    }

    Motherboard(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const float& price,
        const float& speed, const std::string& doubleDataRate, const int& numberOfRAMSlots, const bool& wifiEnabled, const bool& integratedGraphics)
        : Product(name, description, brand, model, price)
    {
        this->speed = speed;
        this->doubleDataRate = getEnumType(DoubleDataRate::toEnumMapping, doubleDataRate);
        this->numberOfRAMSlots = numberOfRAMSlots;
        this->wifiEnabled = wifiEnabled;
        this->integratedGraphics = integratedGraphics;
    }

    Motherboard(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const float& price,
        const float& speed, const DoubleDataRate::DoubleDataRate& doubleDataRate, const int& numberOfRAMSlots, const bool& wifiEnabled, const bool& integratedGraphics)
        : Product(name, description, brand, model, price)
    {
        this->speed = speed;
        this->doubleDataRate = doubleDataRate;
        this->numberOfRAMSlots = numberOfRAMSlots;
        this->wifiEnabled = wifiEnabled;
        this->integratedGraphics = integratedGraphics;
    }

    std::string toString() const override
    {
        return "some string";
    }
};
