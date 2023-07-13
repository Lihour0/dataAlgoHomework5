#include<iostream>
#include <iostream>
#include <array>
#include <string>


struct CustomerType {
    int id;
    std::string name;
    char gender;
    std::string birthdate;
    std::string address;
    std::string telephone;
};

int main() {
const int SIZE = 50;
    std::array<CustomerType, SIZE> people;

    for (CustomerType &p : people) {
        std::cout << "Enter id: ";
        std::cin >> p.id;
        std::cout << "Enter name: ";
        std::cin.ignore();
        std::getline(std::cin, p.name);
        std::cout << "Enter gender: ";
        std::cin >> p.gender;
        std::cout << "Enter birthdate: ";
        std::cin.ignore();
        std::getline(std::cin, p.birthdate);
        std::cout << "Enter address: ";
        std::getline(std::cin, p.address);
        std::cout << "Enter telephone: ";
        std::getline(std::cin, p.telephone);
    }

    std::cout << "ID\tName\tGender\tBirthdate\tAddress\tTelephone\n";
    for (const CustomerType &p : people) {
        std::cout << p.id << "\t" << p.name.substr(0, 18) + ".." << "\t" << p.gender << "\t" << p.birthdate.substr(0, 10) + ".." << "\t" << p.address.substr(0, 28) + ".." << "\t" << p.telephone.substr(0, 10) + ".." << "\n";
    }

}
