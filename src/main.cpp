#include <iostream>
#include <limits>
#include <string>
#include <cctype>
#include "Station.h"
#include "ProcessFlow.h"
#include "FinishedProducts.h"


void showMenu() {
    std::cout << "1. Set up process flow (Ex: A->B->C).\n";
    std::cout << "2. Input raw material.\n";
    std::cout << "3. Show all finished products.\n";
    std::cout << "4. Show the number of times each station has been processed.\n";
    std::cout << "5. Exit.\n";
}

int main(int argc, char *argv[]) {
    ProcessFlow processFlow;
    FinishedProducts finishedProducts;
    finishedProducts.loadProducts();
    
    int choice;
    while (true) {
        showMenu();
        std::cout << "Choose an option: ";
        std::cin >> choice;
        
        if (std::cin.fail()) { // check if last cin action failed (e.g. String into integer variable)
            std::cin.clear(); // clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear input buffer up to size of the stream
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            std::string flow;
            std::cout << "Enter process flow (Ex: A->B->C->D): ";
            std::cin >> flow;

            bool isValid = true;  // Flag to track if the string is valid

            for (char ch : flow) {
                // Convert to uppercase to handle lowercase letters
                ch = std::toupper(ch);

                // If the character is not in the valid characters string
                if (validChars.find(ch) == std::string::npos) {
                    isValid = false;  // Mark the string as invalid
                    break;            // No need to check further
                }
            }

            if (!isValid) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear input buffer up to size of the stream
                std::cout << "Invalid input. Please enter only one the following characters: A, B, C, D, -, or >\n";
                continue;
            }
    
            processFlow = ProcessFlow();  // Reset the flow
            for (char station : flow) {
                if (station == 'A') processFlow.addStation(new StationA());
                else if (station == 'B') processFlow.addStation(new StationB());
                else if (station == 'C') processFlow.addStation(new StationC());
                else if (station == 'D') processFlow.addStation(new StationD(new StationA()));
            }
            std::cout << "Programmed program flow is: " << flow << "\n";

        } 
        else if (choice == 2) {
            int material;
            std::cout << "Enter raw material: ";
            std::cin >> material;
            
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear input buffer up to size of the stream
                std::cout << "Invalid input. Must be a number.\n";
                continue;
            }

            int finishedProduct = processFlow.processMaterial(material);
            finishedProducts.addProduct(finishedProduct);
            std::cout << "Finished product: " << finishedProduct << "\n";
        } 
        else if (choice == 3) {
            finishedProducts.showProducts();
        } 
        else if (choice == 4) {
            processFlow.showStationUsage();
        } 
        else if (choice == 5) {
            finishedProducts.saveProducts();
            std::cout << "Exiting the application.\n";
            break;
        } 
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

