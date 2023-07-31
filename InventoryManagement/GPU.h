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
                this->displayOutputs.push_back(new DisplayOutput::DisplayOutput(displayOutput));
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
                this->displayOutputs.push_back(new DisplayOutput::DisplayOutput(displayOutput));
            }
            catch (const std::exception& e)
            {
                std::cout << "Failed to add display out " << item << ". Error: " << e.what() << std::endl;
            }
        }
    }

    GPU(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const float& price,
        const int& vram, const std::vector<DisplayOutput::DisplayOutput*> displayOutputs)
        : Product(name, description, brand, model, price)
    {
        this->vram = vram;
        this->displayOutputs = displayOutputs;
    }

    std::string getVRAM() const
    {
        return std::to_string(vram) + " GB";
    }

    std::string getDisplayPorts() const
    {
        std::string displayPorts;
        for (int i = 0; i < displayOutputs.size(); i++)
        {
            displayPorts.append(getEnumType(DisplayOutput::toStringMapping, *(displayOutputs[i])));
            if (i != displayOutputs.size() - 1)
            {
                displayPorts.append(", ");
            }
        }

        return displayPorts;
    }

    std::string toString() const override
    {
        return format("{0:15s}{1}\n{2:15s}{3}\n{4:15s}{5}\n{6:15s}{7}\n{8:15s}{9}\n{10:15s}{11}\n{12:15s}{13}\n{14:15s}{15}",
            "Name:", getName(), "Description:", getDescription(), "Brand:", getBrand(), "Model:", getModel(), "SKU:", getSKU(), "Price:", getPrice(),
            "VRAM:", getVRAM(), "Display Ports:", getDisplayPorts());
    }
};
