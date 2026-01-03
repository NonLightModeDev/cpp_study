#include <iostream>

class A {
  int x {10}; // inicializador de membro padrão (será ignorado, pois já existe um inicializador na liosta de inicializadores de membros)
  int y {20}; // inicialziador de membro padrão (será usado)
  int z;

  public:
    A(int _x, int _y, int _z): x(_x), y(_y), z(_z) {}

    void show() {
      std::cout << "X: " << x << std::endl;
      std::cout << "Y: " << y << std::endl;
      std::cout << "Z: " << z << std::endl;
    }
};

int main() {
  A a(2, 3, 4);
  a.show();

  return 0;
}