#pragma once
#include <vector>

#include "DisplayOutput.h"
#include "EnumHelpers.h"
#include "Product.h"

class GPU : public Product
{
private:
    int vram; // GB
    std::vector<DisplayOutput::DisplayOutput*> displayOutputs;
public:
    GPU(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const std::string& sku, const float& price,
        const int& vram, const std::vector<std::string>& displayOutputs)
        : Product(name, description, brand, model, sku, price)
    {
        this->vram = vram;
        for (std::string item : displayOutputs)
        {
            try
            {
                DisplayOutput::DisplayOutput displayOutput = getEnumType(DisplayOutput::toEnumMapping, item);
                this->displayOutputs.push_back(&displayOutput);
            }
            catch (const std::exception& e)
            {
                std::cout << "Failed to add display out " << item << ". Error: " << e.what() << std::endl;
            }
        }
    }

    GPU(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const float& price,
        const int& vram, const std::vector<std::string>& displayOutputs)
        : Product(name, description, brand, model, price)
    {
        this->vram = vram;
        for (std::string item : displayOutputs)
        {
            try
            {
                DisplayOutput::DisplayOutput displayOutput = getEnumType(DisplayOutput::toEnumMapping, item);
                this->displayOutputs.push_back(&displayOutput);
            }
            catch (const std::exception& e)
            {
                std::cout << "Failed to add display out " << item << ". Error: " << e.what() << std::endl;
            }
        }
    }

    GPU(std::string& name, std::string& description, std::string& brand, std::string& model, float& price,
        int& vram, std::vector<DisplayOutput::DisplayOutput*> displayOutputs)
        : Product(name, description, brand, model, price)
    {
        this->vram = vram;
        this->displayOutputs = displayOutputs;
    }

    std::string toString() const override
    {
        return "some string";
    }
};
