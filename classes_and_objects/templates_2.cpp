#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Caixa {
  private:
    T item;
  
  public:
    Caixa(const T &objeto): item(objeto) {}

    T getItem() const {
      return item;
    }
};

int main() {
  Caixa<int> caixaInteiro(10);
  cout << "Item na caixa: " << caixaInteiro.getItem() << endl;

  cout << endl;

  Caixa<string> caixaString("Hello World!");
  cout << "Item na caixa: " << caixaString.getItem() << endl;

  return 0;
}