#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Lista {
  private:
    T elementos[5];
    int tamanho;

  public:
    Lista(): tamanho(0) {}

    void adicionar(const T &elemento) {
      if(tamanho < 5)
        elementos[tamanho++] = elemento;
      else
        cout << "A lista está cheia!" << endl;
    }

    void imprimir() {
      cout << "Elementos da lista: ";

      for(short int i = 0; i < tamanho; i++) {
        cout << elementos[i];
        if (i != tamanho - 1)
          cout << ", ";
      }
      cout << endl;
    }
};

int main() {
  Lista<int> listaInteiros;
  listaInteiros.adicionar(1);
  listaInteiros.adicionar(2);
  listaInteiros.adicionar(3);
  listaInteiros.adicionar(4);
  listaInteiros.adicionar(5);
  listaInteiros.adicionar(6);
  listaInteiros.imprimir();


  Lista<string> listaStrings;
  listaStrings.adicionar("um");
  listaStrings.adicionar("dois");
  listaStrings.adicionar("três");
  listaStrings.adicionar("quatro");
  listaStrings.adicionar("cinco");
  listaStrings.adicionar("seis");
  listaStrings.imprimir();

  return 0;
}