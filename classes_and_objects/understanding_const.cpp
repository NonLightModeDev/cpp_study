#include <iostream>
#include <string>

using namespace std;

class Person {
  public:
    string name;
    int age;

    static int count;

    Person(string _name, int _age)
      : name(_name)
      , age(_age)
    {
      count++;
    }

    ~Person() { count--; }
};

int Person::count = 0; // independentemente da visibilidade, toda variável estática só pode ser inicializada fora da classe

int main() {
  const Person *p = new Person("Irineu", 29);
  // const antes do * impede que alteremos o contéudo do endereço armazenado pelo ponteiro (pelo visto, também impede o uso do this), mas podemos alterar o conteúdo do ponteiro (ou seja, fazer o ponteiro apontar para outro endereço)
  // Ou seja, faz com que o conteúdo do endereço armazenado pelo ponteiro p seja somente leitura!!

 // (*p).age = 30; // dar erro de compilação

  cout << "Name: " << p->name << " | Age: " << p->age << endl; 

  p = new Person("Maria", 23); // funciona

  cout << "Name: " << p->name << " | Age: " << p->age << endl; 

  
  
  cout << "\n\n" << endl;


  // ---------


  Person * const ptr = new Person("Katarina", 19); // const depois do * faz com que não seja possível alterar o conteúdo do ponteiro ptr, ou seja, o conteúdo do endereço armazenado pelo ptr pode ser alterado
  // Ou seja, a variável ptr é somente leitura
  cout << "Name: " << ptr->name << " | Age: " << ptr->age << endl; 
  ptr->age = 40;
  cout << "Name: " << ptr->name << " | Age: " << ptr->age << endl;

  // ptr = new Person("Antônio", 39); // erro de compilação
  
  
  
  cout << "\n\n" << endl;


  // ---------
  const Person * const ptrTest = new Person("Gertrudes", 18); // um const antes e um const depois do * torna o conteúdo do endereço armazenado pelo ponteiro ptrTest e o próprio ponteiro ptrTest somente leitura
  // Ou seja, aplica os dois casos anteriores!

  cout << "Name: " << ptrTest->name << " | Age: " << ptrTest->age << endl;

  // (*ptrTest).age = 27; // erro de compilação
  // ptrTest = new Person("Jackson", 29); // de compilação

  cout << "Name: " << ptrTest->name << " | Age: " << ptrTest->age << endl;

  return 0;
}