#include <iostream>

using namespace std;

class Ponto {
  public:
    int x, y;

    Ponto(int _x, int _y): x(_x), y(_y) {}

    bool operator==(const Ponto &p) const {
      return (x==p.x && y==p.y);
    }
};

int main() {
  Ponto p1(3, 4);
  Ponto p2(3, 4);
  Ponto p3(1, 2);

  if(p1 == p2) {
    cout << "p1 é igual a p2" << endl;
  } else {
    cout << "p1 não é igual a p2" << endl;
  }

  if(p1 == p3) {
    cout << "p1 é igual a p3" << endl;
  } else {
    cout << "p1 não é igual a p3" << endl;
  }

  return 0;
}