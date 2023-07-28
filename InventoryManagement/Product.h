#pragma once
#include <string>;

class Product
{
private:
    std::string name;
    std::string description;
    std::string brand;
    std::string model;
    std::string sku;
    float price;
public:
    Product(std::string& name, std::string& description, std::string& brand, std::string& model, float& price)
    {
        this->name = name;
        this->description = description;
        this->brand = brand;
        this->model = model;
        this->price = price;

        // generate sku
        this->sku = "";
    }

    std::string getName()
    {
        return name;
    }

    void setName(std::string& name)
    {
        this->name = name;
    }

    std::string getDescription()
    {
        return description;
    }

    void setDescription(std::string& description)
    {
        this->description = description;
    }

    std::string getBrand()
    {
        return brand;
    }

    void setBrand(std::string& brand)
    {
        this->brand = brand;
    }

    std::string getModel()
    {
        return model;
    }

    void setModel(std::string& model)
    {
        this->model = model;
    }

    std::string getSKU()
    {
        return sku;
    }

    float getPrice()
    {
        return price;
    }

    void setPrice(float& price)
    {
        this->price = price;
    }
};
