#include <iostream> // incluindo a bibliotca iostream
#include <memory>
#include <string>

using namespace std;

class Person {
  string name;
  int age;

  public:
    Person(string _name, int _age): name(_name), age(_age) {
      cout << "Constructing the Person object..." << endl;
    }

    ~Person() {
      cout << "Destructing the Person object {name: " << name << ", age: " << age << "}" << endl << endl;
    }

    void toGreet() {
      cout << "Hi! My name is " << name << " and I'm " << age << " years old." << endl;
    }
};

Person* testing__unique_ptr() {
  unique_ptr<Person> p = make_unique<Person>("Irineu", 23); // p é dono do ponteiro
  Person *ptr = p.get(); // funciona! ptr, neste  caso, não é dono do ponteiro, apenas o observa. É um ponteiro cru
  ptr->toGreet();
  (*p).toGreet(); // é possível usar o operador * para fazer desreferenciação (a classe faz sobrecarga de operador)

  // unique_ptr<Person> pTest = p; // erro de compilação! 

  return ptr;
}

shared_ptr<Person> testing__shared_ptr() {
  shared_ptr<Person> p1 = make_shared<Person>("Maria", 19);
  p1->toGreet();

  shared_ptr<Person> p2 = p1; // funciona, pois shared_ptr é um ponteiro compartilhado.
  p2->toGreet();

  return p2;
}

shared_ptr<Person> testing__weak_ptr() {
  shared_ptr<Person> p = make_shared<Person>("Benedito", 17);
  p->toGreet();

  return p;
}

int main() {
  cout << "unique_ptr: " << endl;
  Person *ptr = testing__unique_ptr();
  cout << "----\n" << endl;
  ptr->toGreet(); // funcionou! ptr->toGreet() "funcionou" (mas poderia não ter funcionado) porque o ponteiro ainda aponta para uma região de memória não reutilizada, mas o objeto já havia sido destruído; acessar esse ponteiro após o fim do tempo de vida do objeto resulta em comportamento indefinido segundo o padrão C++.
  
  cout << "shared_ptr: " << endl;
  shared_ptr<Person> sharedptr = testing__shared_ptr(); // copia o objeto retornado para ptr2
  cout << "----\n" << endl;
  sharedptr->toGreet();

  cout << "weak_ptr: " << endl;
  weak_ptr<Person> weakptr = testing__weak_ptr();
  if(weakptr.expired()) {
    cout << "The object returned by the function no longer exists." << endl;
  } else {
    weakptr.lock()->toGreet();
  }

  return 0;
}