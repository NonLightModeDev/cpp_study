#include <iostream>
#include <string>

using namespace std;

class Vetor {
  public:
    int x, y;
    
    Vetor(int _x, int _y): x(_x), y(_y) {}

    Vetor operator+(const Vetor &v) const { // Este "const" significa que essa função não pode modificar o objeto que a chamou
      return Vetor(x + v.x, y + v.y);
    }

    void imprimir() const { // Este "const" significa que essa função não pode modificar o objeto que a chamou
      cout << "Vetor(" << x << ", " << y << ")" << endl;
    }
};

int main() {
  Vetor v1(3, 4);
  Vetor v2(1, 2);

  Vetor resultado = v1 + v2;
  // "v1 + v2" vai resultar num novo objeto Vetor. "Vetor resultado" vai criar um objeto vetor copiando o objeto resultado de "v1 + v2"
  resultado.imprimir();

  return 0;
}