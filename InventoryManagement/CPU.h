#pragma once
#include "Product.h"

class CPU : public Product
{
private:
    int numberOfCores;
    int numberOfThreads;
    float frequency; // GHz
public:
    CPU(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const std::string& sku, const float& price,
        const int& numberOfCores, const int& numberOfThreads, const float& frequency)
        : Product(name, description, brand, model, sku, price)
    {
        this->numberOfCores = numberOfCores;
        this->numberOfThreads = numberOfThreads;
        this->frequency = frequency;
    }

    CPU(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const float& price,
        const int& numberOfCores, const int& numberOfThreads, const float& frequency)
        : Product(name, description, brand, model, price)
    {
        this->numberOfCores = numberOfCores;
        this->numberOfThreads = numberOfThreads;
        this->frequency = frequency;
    }

    std::string toString() const override
    {
        return "some string";
    }
};
