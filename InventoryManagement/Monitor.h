#pragma once
#include <list>
#include "Product.h"
#include "ScreenType.h"
#include "DisplayOutput.h"
#include "EnumHelpers.h"

class Monitor : public Product
{
private:
    float size;
    int refreshRate;
    ScreenType::ScreenType screenType;
    std::vector<DisplayOutput::DisplayOutput*> displayOutputs;
public:
    Monitor(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const std::string& sku, const float& price,
        const float& size, const int& refreshRate, const std::string& screenType, const std::vector<std::string>& displayOutputs)
        : Product(name, description, brand, model, sku, price)
    {
        this->size = size;
        this->refreshRate = refreshRate;
        this->screenType = getEnumType(ScreenType::toEnumMapping, screenType);
        for (std::string item : displayOutputs)
        {
            try
            {
                DisplayOutput::DisplayOutput displayOutput = getEnumType(DisplayOutput::toEnumMapping, item);
                this->displayOutputs.push_back(new DisplayOutput::DisplayOutput(displayOutput));
            }
            catch (const std::logic_error& e)
            {

            }
            catch (const std::exception& e)
            {

            }
        }
    }

    Monitor(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const float& price,
        const float& size, const int& refreshRate, const std::string& screenType, const std::vector<std::string>& displayOutputs)
        : Product(name, description, brand, model, price)
    {
        this->size = size;
        this->refreshRate = refreshRate;
        this->screenType = getEnumType(ScreenType::toEnumMapping, screenType);
        for (std::string item : displayOutputs)
        {
            try
            {
                DisplayOutput::DisplayOutput displayOutput = getEnumType(DisplayOutput::toEnumMapping, item);
                this->displayOutputs.push_back(new DisplayOutput::DisplayOutput(displayOutput));
            }
            catch (const std::logic_error& e)
            {

            }
            catch (const std::exception& e)
            {

            }
        }
    }

    Monitor(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const float& price,
        const float& size, const int& refreshRate, const ScreenType::ScreenType& screenType, const std::vector<std::string>& displayOutputs)
        : Product(name, description, brand, model, price)
    {
        this->size = size;
        this->refreshRate = refreshRate;
        this->screenType = screenType;
        for (std::string item : displayOutputs)
        {
            try
            {
                DisplayOutput::DisplayOutput displayOutput = getEnumType(DisplayOutput::toEnumMapping, item);
                this->displayOutputs.push_back(new DisplayOutput::DisplayOutput(displayOutput));
            }
            catch (const std::logic_error& e)
            {

            }
            catch (const std::exception& e)
            {

            }
        }
    }

    Monitor(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const float& price,
        const float& size, const int& refreshRate, const std::string& screenType, const std::vector<DisplayOutput::DisplayOutput*>& displayOutputs)
        : Product(name, description, brand, model, price)
    {
        this->size = size;
        this->refreshRate = refreshRate;
        this->screenType = getEnumType(ScreenType::toEnumMapping, screenType);
        this->displayOutputs = displayOutputs;
    }

    Monitor(const std::string& name, const std::string& description, const std::string& brand, const std::string& model, const float& price,
        const float& size, const int& refreshRate, const ScreenType::ScreenType& screenType, const std::vector<DisplayOutput::DisplayOutput*>& displayOutputs)
        : Product(name, description, brand, model, price)
    {
        this->size = size;
        this->refreshRate = refreshRate;
        this->screenType = screenType;
        this->displayOutputs = displayOutputs;
    }

    std::string toString() const override
    {
        return "some string";
    }
};
