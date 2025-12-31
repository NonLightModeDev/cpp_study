#include <iostream>

class B;

class A {
  int valueA;

  public:
    A(int v): valueA(v) {}

    friend void showValueA(A objectA);
};

class B {
  int valueB;

  public:
    B(int v): valueB(v) {}

    friend void showValueB(B objectB);
};

void showValueB(B objectB) {
      std::cout << "ValueB: " << objectB.valueB << std::endl;
}

void showValueA(A objectA) {
      std::cout << "ValueA: " << objectA.valueA << std::endl;
}

int main() {
  A a(10);
  B b(25);

  // std::cout << a.valueA << std::endl; valueA privado assim como valueB

  showValueB(b);
  showValueA(a);

  return 0;
}