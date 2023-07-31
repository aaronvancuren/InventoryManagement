#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <list>
#include <vector>

#include "CPU.h"
#include "GPU.h"
#include "Monitor.h"
#include "Motherboard.h"
#include "PowerSupply.h"
#include "Product.h"
#include "RAM.h"
#include "Storage.h"

// Namespaces
namespace fs = std::filesystem;

class Inventory
{
private:
    std::list<Product*> products;

    std::vector<std::string> ParseInventoryFile(std::string productText)
    {
        std::vector<std::string> productProperties;
        do
        {
            int endIndex = 0;
            if (productText[0] == '[')
            {
                endIndex = productText.find(']');
                std::string productProperty = productText.substr(1, endIndex - 1);
                productProperties.push_back(productProperty);
                productText = productText.substr(endIndex + 1, productText.size());
            }
            else if (productText[0] == '{')
            {
                endIndex = productText.find('}');
                std::string productListProperty = productText.substr(1, endIndex - 1);
                std::vector<std::string> nestedProperties = ParseInventoryFile(productListProperty);
                productText = productText.substr(endIndex + 1, productText.size());

                productListProperty = "";
                for (int i = 0; i < nestedProperties.size(); i++)
                {
                    productListProperty.append(nestedProperties[i]);
                    if (i < nestedProperties.size() - 1)
                    {
                        productListProperty.append(",");
                    }
                }

                productProperties.push_back(productListProperty);
            }
        } while (!productText.empty());

        return productProperties;
    }

    std::vector<std::string> ParsePropertyList(std::string propertyList)
    {
        std::vector<std::string> properties;
        do
        {
            int endIndex = 0;
            endIndex = propertyList.find(',');
            if (endIndex == -1)
            {
                endIndex = propertyList.size();
                properties.push_back(propertyList.substr(0, endIndex));
                propertyList = propertyList.substr(endIndex, propertyList.size());
            }
            else
            {
                properties.push_back(propertyList.substr(0, endIndex));
                propertyList = propertyList.substr(endIndex + 1, propertyList.size());
            }

        } while (!propertyList.empty());

        return properties;
    }

public:
    Inventory(fs::path inventoryFilePath)
    {
        std::ifstream inventoryFile;
        if (!inventoryFile.is_open())
        {
            inventoryFile.open(inventoryFilePath);
        }

        if (inventoryFile.is_open())
        {
            while (inventoryFile)
            {
                std::string productText;
                std::getline(inventoryFile, productText, '\n');
                std::vector<std::string> productProperties = ParseInventoryFile(productText);
                if (productText.empty())
                {
                    inventoryFile.close();
                    continue;
                }

                Product* product = 0;
                std::string productType = productProperties[0];
                // Index 1 - 6 are Product parameters
                if (productType == "class CPU")
                {
                    product = new CPU(productProperties[1], productProperties[2], productProperties[3], productProperties[4], productProperties[5], stof(productProperties[6]),
                        stoi(productProperties[7]), stoi(productProperties[8]), stof(productProperties[9]));
                }
                else if (productType == "class GPU")
                {
                    std::vector<std::string> displayOutputs = ParsePropertyList(productProperties[8]);
                    product = new GPU(productProperties[1], productProperties[2], productProperties[3], productProperties[4], productProperties[5], stof(productProperties[6]),
                        stoi(productProperties[7]), displayOutputs);
                }
                else if (productType == "class Monitor")
                {
                    std::vector<std::string> displayOutputs = ParsePropertyList(productProperties[8]);
                    product = new Monitor(productProperties[1], productProperties[2], productProperties[3], productProperties[4], productProperties[5], stof(productProperties[6]),
                        stof(productProperties[7]), stoi(productProperties[8]), productProperties[9], displayOutputs);
                }
                else if (productType == "class Motherboard")
                {
                    product = new Motherboard(productProperties[1], productProperties[2], productProperties[3], productProperties[4], productProperties[5], stof(productProperties[6]),
                        stof(productProperties[7]), productProperties[8], stoi(productProperties[9]), stoi(productProperties[10]), stoi(productProperties[11]));
                }
                else if (productType == "class PowerSupply")
                {
                    product = new PowerSupply(productProperties[1], productProperties[2], productProperties[3], productProperties[4], productProperties[5], stof(productProperties[6]),
                        stoi(productProperties[7]), productProperties[8], stoi(productProperties[9]));
                }
                else if (productType == "class RAM")
                {
                    product = new RAM(productProperties[1], productProperties[2], productProperties[3], productProperties[4], productProperties[5], stof(productProperties[6]),
                        stof(productProperties[7]), productProperties[8], stoi(productProperties[9]));
                }
                else if (productType == "class Storage")
                {
                    product = new Storage(productProperties[1], productProperties[2], productProperties[3], productProperties[4], productProperties[5], stof(productProperties[6]),
                        productProperties[7], stoi(productProperties[8]));
                }
                else
                {
                    std::cout << "Invalid product listings" << std::endl;
                    continue;
                }

                products.push_back(product);
            }
        }
    }

    std::list<Product*> getProducts()
    {
        return products;
    }

    void addProduct(Product& product)
    {
        products.push_back(&product);
    }

    void removeProduct(std::string productSKU)
    {
        std::erase_if(products, [productSKU](Product* x) { return x->getSKU() == productSKU;});
    }

    double inventoryCarryingCost()
    {
        double totalCost = 0;
        for(Product* product : products)
        {
            totalCost += product->getPrice();
        }

        return totalCost;
    }
};

