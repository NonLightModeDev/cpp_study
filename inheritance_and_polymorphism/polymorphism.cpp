#include <iostream>
#include <string>

using namespace std;

class Animal {
  public:
    virtual void fazerSom() { // o "virtual" habilita a ligação dinâmica (dynamic binding)
      cout << "O animal está fazendo um som." << endl;
    }
};

class Cachorro : public Animal {
  public:
    void fazerSom() override {
      cout << "O cachorro está latindo." << endl;
    }
};

class Gato : public Animal {
  public:
    void fazerSom() override {
      cout << "O gato está miando." << endl;
    }
};

int main() {
  Animal *animal;

  Cachorro cachorro;

  animal = &cachorro;
  animal->fazerSom(); // chama a implementação da classe Cachorro

  Gato gato;
  animal = &gato;
  animal->fazerSom(); // chama a implementação da classe Gato

  Animal animalObj;
  animalObj.fazerSom(); // implementação padrão da classe Animal

  return 0;
}