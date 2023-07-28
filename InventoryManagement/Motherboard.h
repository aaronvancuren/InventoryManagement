#pragma once
#include "Product.h"

class Motherboard : public Product
{
private:
public:
    Motherboard(std::string& name, std::string& description, std::string& brand, std::string& model, float& price)
        : Product(name, description, brand, model, price)
    {

    }
};
