#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ifstream file("in_file.txt");
  std::string line;

  if(file.is_open()) {
    while(std::getline(file, line)) {
      std::cout << line << std::endl;
    }

    file.close();
  } else {
    std::cerr << "It was not possible to open the file!" << std::endl;
  }
}