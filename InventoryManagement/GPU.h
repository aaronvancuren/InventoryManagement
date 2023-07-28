#pragma once
#include <vector>
#include "Product.h"
#include "DisplayOutput.h"
#include "EnumHelpers.h"

class GPU : public Product
{
private:
    int vram; // GB
    std::vector<DisplayOutput::DisplayOutput*> displayOutputs;
public:
    GPU(std::string& name, std::string& description, std::string& brand, std::string& model, float& price, int& vram, std::vector<std::string>& displayOutputs)
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
            catch (const std::logic_error& e)
            {

            }
            catch (const std::exception& e)
            {

            }
        }
    }

    GPU(std::string& name, std::string& description, std::string& brand, std::string& model, float& price, int& vram, std::vector<DisplayOutput::DisplayOutput*> displayOutputs)
        : Product(name, description, brand, model, price)
    {
        this->vram = vram;
        this->displayOutputs = displayOutputs;
    }
};
