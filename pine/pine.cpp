#include <iostream>
#include <cmath>

short int createTopOfPine(short int numberOfLines) {
  short int numberOfSpaces = numberOfLines - 1;
  short int numberOfAsterisks = 1;

  for(short int i = 0; i < numberOfLines; i++) {
    for(short int s = numberOfSpaces; s > 0; s--) {
      std::cout << " ";
    }

    for(short int a = 0; a < numberOfAsterisks; a++) {
      std::cout << "*";
    }

    std::cout << std::endl;
    numberOfSpaces--;
    numberOfAsterisks += 2;
  }

  return numberOfAsterisks - 2;
}

void createBaseOfPine(short int numberOfAsterisks) {
  short int bNumberOfAsterisks;
  short int bNumberOfLines = 2;
  
  if (numberOfAsterisks < 11) {
    bNumberOfAsterisks = 1;
  } else if (numberOfAsterisks < 21) {
    bNumberOfAsterisks = 3;
  } else {
    bNumberOfAsterisks = 5;
  }

  short int bNumberOfSpaces = (numberOfAsterisks - bNumberOfAsterisks) / 2;

  for(short int i = 0; i < bNumberOfLines; i++) {
    for(short int j = 0; j < bNumberOfSpaces; j++) {
      std::cout << " ";
    }

    for(short int k = 0; k < bNumberOfAsterisks; k++) {
      std::cout << "*";
    }
    std::cout << std::endl;
  }
}

void createPine(short int numberOfLines) {
  short int numberOfAsterisks = createTopOfPine(numberOfLines);
  createBaseOfPine(numberOfAsterisks);
}

int main() {
  short int numberOfLines;
  std::cout << "Enter number of lines (minimum: 3) -> ";
  std::cin >> numberOfLines;
  std::cout << std::endl;
  if(numberOfLines < 3) std::cout << "The number of lines is lower than expected." << std::endl;
  else createPine(numberOfLines);
  std::cout << std::endl;
  return 0;
}