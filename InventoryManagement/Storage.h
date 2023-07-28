#pragma once
#include "Product.h"

class Storage : public Product
{
private:
public:
    Storage(std::string& name, std::string& description, std::string& brand, std::string& model, float& price)
        : Product(name, description, brand, model, price)
    {

    }
};
