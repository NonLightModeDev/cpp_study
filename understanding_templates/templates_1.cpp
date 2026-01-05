#include <iostream>

using namespace std;

template <typename T>
T encontrarMaximo(T a, T b) {
  return (a > b)? a : b;
}

int main() {
  int maximoInt = encontrarMaximo<int>(10, 20);
  cout << "Máximo entre 10 e 20: " << maximoInt << endl;

  float maximoFloat = encontrarMaximo(3.5f, 7.8f); // neste caso, será feito uma inferência de tipo já que está sem o <>
  cout << "Máximo entre 3.5 e 7.8: " << maximoFloat << endl;

  return 0;
}