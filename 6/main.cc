
#include <iostream>
#include <string>
#include <array>
#include <vector>

struct WaterUsageType {
  int cusId;
  std::string date;
  int oldnum;
  int newnum ;
  void inputData(){
    std::array<WaterUsageType, 1> customers;

    for (WaterUsageType &c : customers) {
      std::cout << "Enter cusId: ";
      std::cin >> c.cusId;
      std::cout << "Enter Date: ";
      std::cin>>c.date;
      std::cout << "Enter oldnum: ";
      std::cin >> c.oldnum;
      std::cout << "Enter newnum: ";
      std::cin >> c.newnum;
    }
  }
  int getUsage(){
    return newnum - oldnum;
  };

  double getPayment(){
     int usage = getUsage();
    double payment = 0.0;
    if (usage <= 10) {
      payment = usage * 1.0;
    } else if (usage <= 30) {
      payment = 10 * 1.0 + (usage - 10) * 2.0;
    } else {
      payment = 10 * 1.0 + 20 * 2.0 + (usage - 30) * 3.0;
    }
    return payment;
  }
  void printRes(){
    int usage = getUsage();
    double payment = getPayment();
    std::cout << "Customer ID: " << cusId << "\n";
    std::cout << "Date: " << date << "\n";
    std::cout << "Usage: " << usage << "\n";
    std::cout << "Payment: $" << payment << "\n";
  };
};


std::vector<WaterUsageType> type;

int main(){
  WaterUsageType hello;
  hello.inputData();
  hello.getUsage();
  hello.getPayment();
  hello.printRes();

}
