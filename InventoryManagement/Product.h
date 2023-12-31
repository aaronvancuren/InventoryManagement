#pragma once
#include <string>
#include "RandomGenerator.h"

class Product
{
private:
    std::string name;
    std::string description;
    std::string brand;
    std::string model;
    std::string sku;
    float price;

    std::string GenerateSKU()
    {
        std::string sku;
        for (int i = 1; i <= 16; i++)
        {
            char randomAlphaNumeric = GetRandomAlphaNumeric();
            sku.push_back(randomAlphaNumeric);
            if (i % 4 == 0 && i != 16)
            {
                sku.push_back('-');
            }
        }

        return sku;
    }
public:
    Product(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const std::string& sku, const float& price)
    {
        this->name = name;
        this->description = description;
        this->brand = brand;
        this->model = model;
        this->sku = sku;
        this->price = price;
    }

    Product(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const float& price)
    {
        this->name = name;
        this->description = description;
        this->brand = brand;
        this->model = model;
        this->sku = GenerateSKU();
        this->price = price;
    }

    std::string getName() const
    {
        return name;
    }

    void setName(std::string& name)
    {
        this->name = name;
    }

    std::string getDescription() const
    {
        return description;
    }

    void setDescription(std::string& description)
    {
        this->description = description;
    }

    std::string getBrand() const
    {
        return brand;
    }

    void setBrand(std::string& brand)
    {
        this->brand = brand;
    }

    std::string getModel() const
    {
        return model;
    }

    void setModel(std::string& model)
    {
        this->model = model;
    }

    std::string getSKU() const
    {
        return sku;
    }

    float getPrice() const
    {
        return price;
    }

    void setPrice(float& price)
    {
        this->price = price;
    }

    virtual std::string toString() const = 0;
};
