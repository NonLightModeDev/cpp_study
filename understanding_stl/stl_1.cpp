#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> numeros = {5, 2, 7, 3, 1};
  
  sort(numeros.begin(), numeros.end());

  for(int numero : numeros) {
    cout << numero << " ";
  }

  cout << endl;

  return 0;
}