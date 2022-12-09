#include <iostream>
#include <cmath>

int algorithm_v2() {

    /*
    
     1 1 2 3 5 8 13 21 34 55 89 ...
         ^     ^       ^        ...

    a posição dos números pares vai de 3 em 3

    podemos fazer o ciclo 3x mais eficiente com este facto

    (n - 1) = (n - 1)-1 + (n - 1)-2
    (n - 2) = (n - 2)-1 + (n - 2)-2
    
    n = (n - 1) + (n - 2)


    Qualquer número na sequencia pode ser calculado com a sequinte formula:

    Fn =(Φn - (1-Φ)n)/√5 , em que
    
    Φ ≈ 1.618034

    */

/*
    constexpr double golden_ratio = 1.618034;
    auto Fn = [&gr = golden_ratio](unsigned long n) -> unsigned long {
        return ( std::pow(gr,n) - std::pow((1.0 - gr), n )) / std::sqrt(5.0);
    };
*/
int algorithm_v2() {
    int counter = 0;
    auto Fn = [](double n) -> double {
        return ( std::pow((1.0 + std::sqrt(5)), n) - std::pow((1.0 - std::sqrt(5)), n) ) / ( std::pow(2, n) * std::sqrt(5) );
        //return ( std::pow(gr,n) - std::pow((1.0 - gr), n )) / std::sqrt(5.0);
    };
    for(unsigned long x = 1;; ++x) {
        if(Fn(x*3) > 4000000) break;
        counter += Fn(x * 3);
    }
    return counter;
}

int main() {

    std::cout << algorithm_v2() << std::endl;;

    auto Fn = [](double n) -> double {
        return ( std::pow((1.0 + std::sqrt(5)), n) - std::pow((1.0 - std::sqrt(5)), n) ) / ( std::pow(2, n) * std::sqrt(5) );
        //return ( std::pow(gr,n) - std::pow((1.0 - gr), n )) / std::sqrt(5.0);
    };


    unsigned long input = 0;
    do {
        unsigned long counter = 0;
        std::cout << std::endl << "n=";
        std::cin >> input;
        std::cout << std::endl << "Existem " << static_cast<int>(input / 3.0) << " pares até " << input << std::endl;
        std::cout << "F("<<input << ") = " << (Fn(input)) << std::endl;
        std::cout << "Pares encontrados:" << std::endl;

        for(int i = 1; i <= input; ++i) {
            unsigned long result = Fn(i);
            if(result % 2 == 0)  {
                std::cout << "\t par nr "<< i << " >"<< result << std::endl;
                counter++;
            }
        }
        std::cout << "eu contei " << counter << " pares" << std::endl;
    } while(input != 0);


    return 0;
}