#include <iostream>
#include <string>

class Person {
  std::string name;

  public:
    void toGreet();
    void setName(std::string name);
    std::string getName();
}; // funciona como uma interface

void Person::toGreet() {
  std::cout << "Hi! My name is " << name << std::endl;
}

void Person::setName(std::string name) {
  this->name = name;
}

std::string Person::getName() {
  return name;
}

int main() {
  Person person;

  person.setName("Irineu");
  std::cout << person.getName() << std::endl;
  person.toGreet();

  return 0;
}