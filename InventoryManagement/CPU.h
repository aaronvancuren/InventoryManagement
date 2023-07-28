#pragma once
#include "Product.h"

class CPU : public Product
{
private:
    int numberOfCores;
    int numberOfThreads;
    float frequency; // GHz
public:
    CPU(std::string& name, std::string& description, std::string& brand, std::string& model, float& price, int& numberOfCores, int& numberOfThreads, float& frequency)
        : Product(name, description, brand, model, price)
    {
        this->numberOfCores = numberOfCores;
        this->numberOfThreads = numberOfThreads;
        this->frequency = frequency;
    }
};
