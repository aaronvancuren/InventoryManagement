#pragma once
#include "Product.h"

class RAM : public Product
{
private:
public:
    RAM(std::string& name, std::string& description, std::string& brand, std::string& model, float& price)
        : Product(name, description, brand, model, price)
    {

    }
};
