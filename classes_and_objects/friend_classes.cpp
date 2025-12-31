#include <iostream>

class B;

class A {
  int secret;

  public:
    A(int s): secret(s) {}
    friend class B; // declara que B é amigo de A, ou seja, A permite que B tenha acesso a todos os seus membros, independentemente de suas visibilidades
    // void showSecretB(B &objectB) {
    //   std::cout << "Secret of B: " << objectB.secret << std::endl;
    // } // erro de compilação, pois B não declarou que A é sua amiga
};

class B {
  int secret;

  public:
    B(int s): secret(s) {}

    void showSecretA(A &objectA) {
      std::cout << "Secret of A: " << objectA.secret << std::endl;
    }
};

int main() {
  A a(10);
  B b(25);

  // a.showSecretB(b); // erro de compilação, pois B não declarou que A é sua amiga
  b.showSecretA(a);
  return 0;
}