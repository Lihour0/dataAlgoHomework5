#include <iostream>
#include <array>
#include <string>
#include <fstream>

const int SIZE = 1;

struct Customer {
    std::string cus_id;
    std::string meter_code;
    int oldnum;
    int newnum;
};

int main() {
    std::array<Customer, SIZE> customers;

    // Read customer data from file
    std::ifstream inFile("waterOperation.txt");
    if (inFile.is_open()) {
        for (Customer &c : customers) {
            inFile >> c.cus_id >> c.meter_code >> c.oldnum >> c.newnum;
        }
        inFile.close();
    } else {
        std::cout << "Unable to open file for reading\n";
    }

    // Print customer data
    std::cout << "cus_id\tmeter_code\toldnum\tnewnum\n";
    for (const Customer &c : customers) {
        std::cout << c.cus_id << "\t" << c.meter_code << "\t" << c.oldnum << "\t" << c.newnum << "\n";
    }

    // Write customer data to file
    std::ofstream outFile("waterOperation.txt");
    if (outFile.is_open()) {
        for (const Customer &c : customers) {
            outFile << c.cus_id << " " << c.meter_code << " " << c.oldnum << " " << c.newnum << "\n";
        }
        outFile.close();
    } else {
        std::cout << "Unable to open file for writing\n";
    }
}

