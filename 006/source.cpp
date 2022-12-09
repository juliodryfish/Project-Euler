#include <iostream>

int algorithm() {

    int sumOfSquares = 0;
    for(int i = 1; i <= 100; ++i) {
        sumOfSquares += (i * i);
    }

    int squareOfSums = 0;
    for(int i = 1; i <= 100; ++i) {
        squareOfSums += i;
    }
    squareOfSums *= squareOfSums;
    std::cout << ">" << squareOfSums << std::endl;
    std::cout << ">" << sumOfSquares << std::endl;
    return squareOfSums - sumOfSquares;
}


int main() {
    std::cout << ":" << algorithm() << std::endl;
    return 0;
}