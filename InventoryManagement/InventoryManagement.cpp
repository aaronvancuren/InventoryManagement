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
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 8:
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
