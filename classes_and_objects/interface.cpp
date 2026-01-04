#include <iostream>

using namespace std;

class IDesenhavel {
  public:
    virtual void desenhar() = 0;
};

class Circulo : public IDesenhavel {
  public:
    void desenhar() override {
      cout << "Desenhando um círculo." << endl;
    }
};

class Quadrado : public IDesenhavel {
  public:
    void desenhar() override {
      cout << "Desenhando um quadrado." << endl;
    }
};

int main() {
  IDesenhavel *desenhaveis[] = {new Circulo(), new Quadrado};

  for(auto desenhavel : desenhaveis) {
    desenhavel->desenhar();
  }

  for(auto desenhavel : desenhaveis) {
    delete desenhavel;
  }

  return 0;
}