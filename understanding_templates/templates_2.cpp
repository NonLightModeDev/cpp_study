#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Pilha {
  private:
    T *elementos;
    int tamanho;
    int capacidade;

  public:
    Pilha(int capacidade): capacidade(capacidade), tamanho(0) {
      elementos = new T[capacidade];
    }

    void empilhar(T elemento) {
      if(tamanho < capacidade) {
        elementos[tamanho++] = elemento;
      } else {
        throw overflow_error("Pilha cheia!");
      }
    }

    T desempilhar() {
      if(tamanho > 0) {
        return elementos[--tamanho];
      }

      throw out_of_range("Pilha vazia!");
    }
};

int main() {
  Pilha<int> pilhaInt(5);
  pilhaInt.empilhar(1);
  pilhaInt.empilhar(2);
  pilhaInt.empilhar(3);
  pilhaInt.empilhar(4);
  pilhaInt.empilhar(5);
  cout << "(Pilha de Inteiros) Elemento desempilhado: " << pilhaInt.desempilhar() << endl;


  Pilha<string> pilhaString(5);
  pilhaString.empilhar("um");
  pilhaString.empilhar("dois");
  pilhaString.empilhar("três");
  pilhaString.empilhar("quatro");
  pilhaString.empilhar("cinco");
  cout << "(Pilha de Strings) Elemento desempilhado: " << pilhaString.desempilhar() << endl;


  return 0;
}