#include <iostream>

using namespace std;

class Animal {
  public:
    virtual void fazerSom() = 0; // "= 0" indica que a função é uma função virtual pura, e uma função virtual pura não tem implementação na classe base. Também indica que toda classe derivada concreta deve, obrigatoriamente, implementar a função. Não pode ser chamada diretamente na classe base. O "= 0" é a sintaxe da linguagem C++ para marcar a função como pure virtual.
    // Quando uma classe tem pelo menos uma função virtual pura (método abstrato), ela vira uma classe abstrata!!!
    /*
    * Pense assim:
    * - virtual → permite polimorfismo
    * - "= 0" → obriga implementação nas subclasses
    * - Classe com "= 0" → classe abstrata
    *  - Classe abstrata → não pode ser instanciada
    */
};

class Cachorro : public Animal {
  public:
    void fazerSom() override { // "override" indica que o método fazerSom() está sendo sobrescrito
      cout << "O cachorro late." << endl;
    }
};

class Gato : public Animal {
  public:
    void fazerSom() override {
      cout << "O gato mia." << endl;
    }
};

int main() {
  Animal *animais[] = {new Cachorro(), new Gato};

  for(auto animal : animais) {
    animal->fazerSom();
  }

  for(auto animal : animais) {
    delete animal;
  }

  return 0;
}
