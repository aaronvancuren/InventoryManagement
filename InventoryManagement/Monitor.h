#pragma once
#include "Product.h"

class Monitor : public Product
{
private:
public:
    Monitor(std::string& name, std::string& description, std::string& brand, std::string& model, float& price)
        : Product(name, description, brand, model, price)
    {

    }
};
