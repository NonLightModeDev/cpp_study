#include <iostream>
#include <string>

using namespace std;

class Animal {
  public:
    void comer() {
      cout << "O animal está comendo." << endl;
    }
};

class Cachorro : public Animal {
  public:
    void latir() {
      cout << "O cachorro está latindo." << endl;
    }
};

int main() {
  Cachorro dog;
  dog.comer();

  dog.latir();

  return 0;
}