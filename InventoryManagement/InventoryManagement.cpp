// Program name: InventoryManagement.cpp
// Author: Aaron Van Curen
// Date last updated: 07/29/2023
// Purpose: Allows a user to manage existing inventory files by showing, adding, and removing products.

// Library & File References
#include <filesystem>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "CPU.h"
#include "EnumHelpers.h"
#include "GPU.h"
#include "Inventory.h"
#include "Monitor.h"
#include "Motherboard.h"
#include "PowerSupply.h"
#include "Product.h"
#include "RAM.h"
#include "Storage.h"

// Namespaces
namespace fs = std::filesystem;

// Constant Variables
const fs::path inventoryPath = fs::current_path().parent_path()/"Inventories";

// Method Declarations
fs::path getSelectedInventoryFilePath();
void ShowProducts(Inventory selectedInventory);
Product& PurchaseCPU();
//Product& PurchaseGPU();
//Product& PurchaseMonitor();
Product& PurchaseMotherboard();
Product& PurchasePowerSupply();
Product& PurchaseRAM();
Product& PurchaseStorage();

int main()
{
    fs::path inventoryFilePath = getSelectedInventoryFilePath();
    Inventory selectedInventory(inventoryFilePath);

    std::string menuInput;
    do
    {
        std::cout << "1. Exit" << std::endl;
        std::cout << "2. Show Available Products" << std::endl;
        std::cout << "3. Purchase A Product" << std::endl;
        std::cout << "4. Sell A Product" << std::endl;
        std::cin >> menuInput;
        try
        {
            std::string purchasingMenuInput;
            std::string sellingMenuInput;
            switch (stoi(menuInput))
            {
            case 1:
                exit(0);
            case 2:
                ShowProducts(selectedInventory);
                break;
            case 3:
                std::cout << "What kind of product are you purchasing?" << std::endl;
                std::cout << "1. Exit" << std::endl;
                std::cout << "2. CPU" << std::endl;
                std::cout << "3. GPU" << std::endl;
                std::cout << "4. Monitor" << std::endl;
                std::cout << "5. Motherboard" << std::endl;
                std::cout << "6. Power Supply" << std::endl;
                std::cout << "7. RAM" << std::endl;
                std::cout << "8. Storage" << std::endl;

                switch (stoi(purchasingMenuInput))
                {
                case 1:
                    continue;
                case 2:
                    selectedInventory.addProduct(PurchaseCPU());
                    break;
                case 3:
                    //selectedInventory.addProduct(PurchaseGPU());
                    break;
                case 4:
                    //selectedInventory.addProduct(PurchaseMonitor());
                    break;
                case 5:
                    selectedInventory.addProduct(PurchaseMotherboard());
                    break;
                case 6:
                    selectedInventory.addProduct(PurchasePowerSupply());
                    break;
                case 7:
                    selectedInventory.addProduct(PurchaseRAM());
                    break;
                case 8:
                    selectedInventory.addProduct(PurchaseStorage());
                    break;
                default:
                    std::cout << "Invalid selection, returning to main menu." << std::endl;
                    continue;
                }
                break;
            case 4:
                std::cout << "Which product are you selling? Please enter the SKU." << std::endl;
                std::cin >> sellingMenuInput;
                selectedInventory.removeProduct(sellingMenuInput);
                break;
            default:
                throw std::invalid_argument("Invalid Selection");
            }
        }
        catch (const std::invalid_argument e)
        {
            std::cout << "Please enter a valid number corresponding to a menu option. Error: " << e.what() << std::endl;
        }
        catch (const std::out_of_range e)
        {
            std::cout << "Please enter a valid number corresponding to a menu option. Error:" << e.what() << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        catch (...)
        {
            exit(-1);
        }
    } while (menuInput != "1");
}

/// <summary>
/// Returns the selected inventory file path that contains products
/// </summary>
/// <returns></returns>
fs::path getSelectedInventoryFilePath()
{
    // Start of menu selection
    std::cout << "Select an inventory" << std::endl;
    std::cout << "1. Exit" << std::endl;

    // Print the list of available inventory files that contain products
    int i = 2;
    std::vector<fs::path> inventoryOptions;
    for (const fs::directory_entry file : fs::directory_iterator(inventoryPath))
    {
        inventoryOptions.push_back(file.path());
        std::cout << i << ". " << file.path().filename() << std::endl;
        i++;
    }

    // File path of the selected inventory
    std::string inventorySelection;
    std::cin >> inventorySelection;
    try
    {
        // Exiting will return an empty file stream
        if (stoi(inventorySelection) == 1)
        {
            exit(1);
        }

        // File stream of selected inventory
        return inventoryOptions[stoi(inventorySelection) - 2];
    }
    catch (const std::exception&)
    {
        // Reprompts the user
        std::cout << "Invalid inventory selection" << std::endl;
        return getSelectedInventoryFilePath();
    }
}

/// <summary>
/// Prints out the products from a given inventory
/// </summary>
/// <param name="selectedInventory"></param>
void ShowProducts(Inventory selectedInventory)
{
    std::list<Product*> products = selectedInventory.getProducts();
    for (Product* product : products)
    {
        std::cout << product->toString() << std::endl << std::endl;
    }
}

Product& PurchaseCPU()
{
    std::string name;
    std::cout << "Enter the CPU name" << std::endl;
    std::getline(std::cin, name);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string description;
    std::cout << "Enter the CPU description" << std::endl;
    std::getline(std::cin, description);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string brand;
    std::cout << "Enter the CPU brand" << std::endl;
    std::getline(std::cin, brand);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string model;
    std::cout << "Enter the CPU model" << std::endl;
    std::getline(std::cin, model);

    float price;
    std::cout << "Enter the CPU price" << std::endl;
    do
    {
        try
        {
            std::cin >> price;
        }
        catch (const std::exception& e)
        {
            std::cout << "Invalid price. Error: " << e.what() << std::endl;
        }
    } while (std::cin.fail());

    float numberOfCores;
    std::cout << "Enter the number of cores the CPU has" << std::endl;
    do
    {
        try
        {
            std::cin >> numberOfCores;
        }
        catch (const std::exception& e)
        {
            std::cout << "Invalid number. Error: " << e.what() << std::endl;
        }
    } while (std::cin.fail());

    float numberOfThreads;
    std::cout << "Enter the number of threads the CPU has" << std::endl;
    do
    {
        try
        {
            std::cin >> numberOfThreads;
        }
        catch (const std::exception& e)
        {
            std::cout << "Invalid number. Error: " << e.what() << std::endl;
        }
    } while (std::cin.fail());

    float frequency;
    std::cout << "Enter the CPU frequency (speed) in GHz" << std::endl;
    do
    {
        try
        {
            std::cin >> frequency;
        }
        catch (const std::exception& e)
        {
            std::cout << "Invalid frequency. Error: " << e.what() << std::endl;
        }
    } while (std::cin.fail());

    return *(new CPU(name, description, brand, model, price, numberOfCores, numberOfThreads, frequency));
}

//Product& PurchaseGPU()
//{
//    std::string name;
//    std::cout << "Enter a product name" << std::endl;
//    std::getline(std::cin, name);
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//    std::string description;
//    std::cout << "Enter a product description" << std::endl;
//    std::getline(std::cin, description);
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//    std::string brand;
//    std::cout << "Enter a product brand" << std::endl;
//    std::getline(std::cin, brand);
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//    std::string model;
//    std::cout << "Enter a product model" << std::endl;
//    std::getline(std::cin, model);
//
//    float price;
//    std::cout << "Enter a product price" << std::endl;
//    do
//    {
//        try
//        {
//            std::cin >> price;
//        }
//        catch (const std::exception& e)
//        {
//            std::cout << "Invalid price. Error: " << e.what() << std::endl;
//        }
//    } while (std::cin.fail());
//}

//Product& PurchaseMonitor()
//{
//    std::string name;
//    std::cout << "Enter a product name" << std::endl;
//    std::getline(std::cin, name);
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//    std::string description;
//    std::cout << "Enter a product description" << std::endl;
//    std::getline(std::cin, description);
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//    std::string brand;
//    std::cout << "Enter a product brand" << std::endl;
//    std::getline(std::cin, brand);
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//    std::string model;
//    std::cout << "Enter a product model" << std::endl;
//    std::getline(std::cin, model);
//
//    float price;
//    std::cout << "Enter a product price" << std::endl;
//    do
//    {
//        try
//        {
//            std::cin >> price;
//        }
//        catch (const std::exception& e)
//        {
//            std::cout << "Invalid price. Error: " << e.what() << std::endl;
//        }
//    } while (std::cin.fail());
//}

Product& PurchaseMotherboard()
{
    std::string name;
    std::cout << "Enter the motherboard name" << std::endl;
    std::getline(std::cin, name);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string description;
    std::cout << "Enter the motherboard description" << std::endl;
    std::getline(std::cin, description);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string brand;
    std::cout << "Enter the motherboard brand" << std::endl;
    std::getline(std::cin, brand);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string model;
    std::cout << "Enter the motherboard model" << std::endl;
    std::getline(std::cin, model);

    float price;
    std::cout << "Enter the motherboard price" << std::endl;
    do
    {
        try
        {
            std::cin >> price;
        }
        catch (const std::exception& e)
        {
            std::cout << "Invalid price. Error: " << e.what() << std::endl;
        }
    } while (std::cin.fail());

    float speed;
    std::cout << "Enter the motherboard speed" << std::endl;
    do
    {
        try
        {
            std::cin >> speed;
        }
        catch (const std::exception& e)
        {
            std::cout << "Invalid speed. Error: " << e.what() << std::endl;
        }
    } while (std::cin.fail());

    DoubleDataRate::DoubleDataRate doubleDataRate = DoubleDataRate::DoubleDataRate::INVALID;
    std::cout << "What kind of DDR would you like?" << std::endl;
    do
    {
        for (int i = 1; ; i++)
        {
            try
            {
                std::string enumValue = getEnumType(DoubleDataRate::toStringMapping, DoubleDataRate::DoubleDataRate(i));
                std::cout << i << ". " << enumValue << std::endl;
            }
            catch (...)
            {
                // Reached the end of the enum class and will break out of the for loop.
                break;
            }
        }

        try
        {
            int userSelection;
            std::cin >> userSelection;
            doubleDataRate = DoubleDataRate::DoubleDataRate(userSelection);
            if (doubleDataRate == DoubleDataRate::DoubleDataRate::INVALID)
            {
                throw std::logic_error("Must select a valid DDR.");
            }
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl << std::endl;
            std::cout << "Select a valid DDR from the following list." << std::endl;
        }
    } while (doubleDataRate == DoubleDataRate::DoubleDataRate::INVALID);

    int ramSlots;
    std::cout << "How many RAM slots does the motherboard have?" << std::endl;
    do
    {
        try
        {
            std::cin >> ramSlots;
        }
        catch (const std::exception& e)
        {
            std::cout << "Invalid speed. Error: " << e.what() << std::endl;
        }
    } while (std::cin.fail());

    std::string wifiEnabledInput;
    std::cout << "Is this wifi enabled? (Y/N)" << std::endl;
    std::cin >> wifiEnabledInput;

    bool wifiEnabled = false;
    if (wifiEnabledInput.starts_with("Y") || wifiEnabledInput.starts_with("y"))
    {
        wifiEnabled = true;
    }

    std::string integratedGraphicsInput;
    std::cout << "Does this have an integrated graphics card? (Y/N)" << std::endl;
    std::cin >> integratedGraphicsInput;

    bool integratedGraphics = false;
    if (integratedGraphicsInput.starts_with("Y") || integratedGraphicsInput.starts_with("y"))
    {
        integratedGraphics = true;
    }

    return *(new Motherboard(name, description, brand, model, price, speed, doubleDataRate, ramSlots, wifiEnabled, integratedGraphics));
}

Product& PurchasePowerSupply()
{
    std::string name;
    std::cout << "Enter a product name" << std::endl;
    std::getline(std::cin, name);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string description;
    std::cout << "Enter a product description" << std::endl;
    std::getline(std::cin, description);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string brand;
    std::cout << "Enter a product brand" << std::endl;
    std::getline(std::cin, brand);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string model;
    std::cout << "Enter a product model" << std::endl;
    std::getline(std::cin, model);

    float price;
    std::cout << "Enter a product price" << std::endl;
    do
    {
        try
        {
            std::cin >> price;
        }
        catch (const std::exception& e)
        {
            std::cout << "Invalid price. Error: " << e.what() << std::endl;
        }
    } while (std::cin.fail());

    int wattage;
    std::cout << "What is the power supply max wattage capacity?" << std::endl;
    do
    {
        try
        {
            std::cin >> wattage;
        }
        catch (const std::exception& e)
        {
            std::cout << "Invalid capacity. Error: " << e.what() << std::endl;
        }
    } while (std::cin.fail());

    PowerSupplyCertification::PowerSupplyCertification powerSupplyCertification = PowerSupplyCertification::PowerSupplyCertification::NOCERTIFICATION;
    std::cout << "What level of certification would you like?" << std::endl;
    do
    {
        for (int i = 1; ; i++)
        {
            try
            {
                std::string enumValue = getEnumType(PowerSupplyCertification::toStringMapping, PowerSupplyCertification::PowerSupplyCertification(i));
                std::cout << i << ". " << enumValue << std::endl;
            }
            catch (...)
            {
                // Reached the end of the enum class and will break out of the for loop.
                break;
            }
        }

        try
        {
            int userSelection;
            std::cin >> userSelection;
            powerSupplyCertification = PowerSupplyCertification::PowerSupplyCertification(userSelection);
            if (powerSupplyCertification == PowerSupplyCertification::PowerSupplyCertification::NOCERTIFICATION)
            {
                throw std::logic_error("Must select a valid power supply certification.");
            }
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl << std::endl;
            std::cout << "Select a valid power supply certification from the following list." << std::endl;
        }
    } while (powerSupplyCertification == PowerSupplyCertification::PowerSupplyCertification::NOCERTIFICATION);

    std::string fullyModularInput;
    std::cout << "Is this fully modular? (Y/N)" << std::endl;
    std::cin >> fullyModularInput;

    bool fullyModular = false;
    if (fullyModularInput.starts_with("Y") || fullyModularInput.starts_with("y"))
    {
        fullyModular = true;
    }

    std::string integratedGraphicsInput;
    std::cout << "Does this have an integrated graphics card? (Y/N)" << std::endl;
    std::cin >> integratedGraphicsInput;

    return *(new PowerSupply(name, description, brand, model, price, wattage, powerSupplyCertification, fullyModular));
}

Product& PurchaseRAM()
{
    std::string name;
    std::cout << "Enter the RAM name" << std::endl;
    std::getline(std::cin, name);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string description;
    std::cout << "Enter the RAM description" << std::endl;
    std::getline(std::cin, description);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string brand;
    std::cout << "Enter the RAM brand" << std::endl;
    std::getline(std::cin, brand);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string model;
    std::cout << "Enter the RAM model" << std::endl;
    std::getline(std::cin, model);

    float price;
    std::cout << "Enter the RAM price" << std::endl;
    do
    {
        try
        {
            std::cin >> price;
        }
        catch (const std::exception& e)
        {
            std::cout << "Invalid price. Error: " << e.what() << std::endl;
        }
    } while (std::cin.fail());

    float speed;
    std::cout << "Enter the RAM speed" << std::endl;
    do
    {
        try
        {
            std::cin >> speed;
        }
        catch (const std::exception& e)
        {
            std::cout << "Invalid speed. Error: " << e.what() << std::endl;
        }
    } while (std::cin.fail());

    DoubleDataRate::DoubleDataRate doubleDataRate = DoubleDataRate::DoubleDataRate::INVALID;
    std::cout << "What kind of DDR would you like?" << std::endl;
    do
    {
        for (int i = 1; ; i++)
        {
            try
            {
                std::string enumValue = getEnumType(DoubleDataRate::toStringMapping, DoubleDataRate::DoubleDataRate(i));
                std::cout << i << ". " << enumValue << std::endl;
            }
            catch (...)
            {
                // Reached the end of the enum class and will break out of the for loop.
                break;
            }
        }

        try
        {
            int userSelection;
            std::cin >> userSelection;
            doubleDataRate = DoubleDataRate::DoubleDataRate(userSelection);
            if (doubleDataRate == DoubleDataRate::DoubleDataRate::INVALID)
            {
                throw std::logic_error("Must select a valid DDR.");
            }
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl << std::endl;
            std::cout << "Select a valid DDR from the following list." << std::endl;
        }
    } while (doubleDataRate == DoubleDataRate::DoubleDataRate::INVALID);

    int ramMemorySize;
    std::cout << "How much memory does the RAM have?" << std::endl;
    do
    {
        try
        {
            std::cin >> ramMemorySize;
        }
        catch (const std::exception& e)
        {
            std::cout << "Invalid size. Error: " << e.what() << std::endl;
        }
    } while (std::cin.fail());

    return *(new RAM(name, description, brand, model, price, speed, doubleDataRate, ramMemorySize));
}

Product& PurchaseStorage()
{
    std::string name;
    std::cout << "Enter a product name" << std::endl;
    std::getline(std::cin, name);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string description;
    std::cout << "Enter a product description" << std::endl;
    std::getline(std::cin, description);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string brand;
    std::cout << "Enter a product brand" << std::endl;
    std::getline(std::cin, brand);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string model;
    std::cout << "Enter a product model" << std::endl;
    std::getline(std::cin, model);

    float price;
    std::cout << "Enter a product price" << std::endl;
    do
    {
        try
        {
            std::cin >> price;
        }
        catch (const std::exception& e)
        {
            std::cout << "Invalid price. Error: " << e.what() << std::endl;
        }
    } while (std::cin.fail());

    StorageDevice::StorageDevice storageDevice = StorageDevice::StorageDevice::NOSTORAGEDEVICE;
    std::cout << "What kind of storage device would you like?" << std::endl;
    do
    {
        for (int i = 1; ; i++)
        {
            try
            {
                std::string enumValue = getEnumType(StorageDevice::toStringMapping, StorageDevice::StorageDevice(i));
                std::cout << i << ". " << enumValue << std::endl;
            }
            catch (...)
            {
                // Reached the end of the enum class and will break out of the for loop.
                break;
            }
        }

        try
        {
            int userSelection;
            std::cin >> userSelection;
            storageDevice = StorageDevice::StorageDevice(userSelection);
            if (storageDevice == StorageDevice::StorageDevice::NOSTORAGEDEVICE)
            {
                throw std::logic_error("Must select a storage device.");
            }
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl << std::endl;
            std::cout << "Select a valid storage device from the following list." << std::endl;
        }
    } while (storageDevice == StorageDevice::StorageDevice::NOSTORAGEDEVICE);

    std::string internalComponentInput;
    std::cout << "Is this an internal hard drive? (Y/N)" << std::endl;
    std::cin >> internalComponentInput;

    bool internalComponent = false;
    if (internalComponentInput.starts_with("Y") || internalComponentInput.starts_with("y"))
    {
        internalComponent = true;
    }

    return *(new Storage(name, description, brand, model, price, storageDevice, internalComponent));
}
