#include <iostream>

class Car {
  public:
    std::string brand;
    int year;

    void info() {
      std::cout << "Brand: " << brand << " | Year: " << year << std::endl;
    }
};

int main() {
  Car car1;
  car1.brand = "Ford";
  car1.year = 2020;

  Car car2;
  car2.brand = "Toyota";
  car2.year = 2018;

  car1.info();
  car2.info();
}