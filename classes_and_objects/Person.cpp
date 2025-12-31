#include <iostream>

class Person {
  std::string name;
  int age;

  public:
    Person(std::string n, int a): name(n), age(a) {
      std::cout << "Constructing a Person object..." << std::endl;
    }

    ~Person() {
      std::cout << "Destructing Person object..." << std::endl;
    }

    void info() {
      std::cout << "Name: " << name << " | Age: " << age << std::endl;
    }
};

int main() {
  Person person1("Irineu", 29);
  Person person2("Maria", 23);

  person1.info();
  person2.info();

  return 0; // Quando sair do escopo de main, o destrutor será chamado.
}