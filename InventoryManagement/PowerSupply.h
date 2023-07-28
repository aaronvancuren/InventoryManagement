#pragma once
#include "Product.h"

class PowerSupply : public Product
{
private:
public:
    PowerSupply(std::string& name, std::string& description, std::string& brand, std::string& model, float& price)
        : Product(name, description, brand, model, price)
    {

    }
};
