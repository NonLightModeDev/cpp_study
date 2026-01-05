#include <iostream>
#include <string>

using namespace std;

double dividir(double numerador, double denominador) {
  if(denominador == 0) {
    throw invalid_argument("Divisão por zero!");
  }

  return numerador / denominador;
}

int main() {
  try {
    double resultado = dividir(10, 0);
    cout << "Resultado: " << resultado << endl;
  } catch(const invalid_argument &e) {
    cerr << "Erro: " << e.what() << endl;
  }

  return 0;
}