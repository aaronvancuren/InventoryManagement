#pragma once
#include "DoubleDataRate.h"
#include "EnumHelpers.h"
#include "Product.h"

class RAM : public Product
{
private:
    float speed; //MHz
    DoubleDataRate::DoubleDataRate doubleDataRate;
    int size; // GB in steps of 2^n
public:
    RAM(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const std::string& sku, const float& price,
        const float& speed, const std::string& doubleDataRate, const int& size)
        : Product(name, description, brand, model, sku, price)
    {
        this->speed = speed;
        this->doubleDataRate = getEnumType(DoubleDataRate::toEnumMapping, doubleDataRate);
        this->size = size;
    }

    RAM(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const float& price,
        const float& speed, const std::string& doubleDataRate, const int& size)
        : Product(name, description, brand, model, price)
    {
        this->speed = speed;
        this->doubleDataRate = getEnumType(DoubleDataRate::toEnumMapping, doubleDataRate);
        this->size = size;
    }

    RAM(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const float& price,
        const float& speed, const DoubleDataRate::DoubleDataRate& doubleDataRate, const int& size)
        : Product(name, description, brand, model, price)
    {
        this->speed = speed;
        this->doubleDataRate = doubleDataRate;
        this->size = size;
    }

    std::string toString() const override
    {
        return "some string";
    }
};
