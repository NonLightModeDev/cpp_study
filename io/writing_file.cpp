#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ofstream file("out_file.txt");

  if(file.is_open()) {
    file << "Hello World!" << std::endl;
    file.close();
    std::cout << "Data saved sucessfully!" << std::endl;
  } else {
    std::cerr << "It was not possible to open the file!" << std::endl;
  }

  return 0;
}