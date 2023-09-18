#include <cmath>
#include <iostream>

int max(int a, int b) {
    return (a < b) ? b : a;
}

int min(int a, int b) {
    return !(b < a)? a : b;
}

//Greatest Common Divisor using the Euclidean algorithm
//https://en.wikipedia.org/wiki/Greatest_common_divisor#Euclidean_algorithm
int gcd(int a, int b) {
    int x = max(a,b);
    int y = min(a,b);

    return (x % y) ? gcd(y, x % y): y;
}

bool coprime(int a, int b) {
    return (gcd(a, b) == 1);
}

//https://projecteuler.net/problem=9
int main() {

    std::cout << gcd(1000, 18) << std::endl;

    int a, b, c;
    int m, n;

    for(n = 2; n < 500; ++n) {
        for(m = 2; m < 500; ++m) {
            if(coprime(m, n) && ((m % 2 == 0 && n % 2 != 0) || (m % 2 != 0 && n % 2 == 0))) {
                a = std::abs(std::pow(m, 2) - std::pow(n,2));
                b = 2 * m * n;
                c = std::pow(m, 2) + std::pow(n,2);
                if(c == (1000 - a - b)) {

                    std::cout << "a " << a << " b " << b << " c " << c << " m " << m << " n " << n << std::endl;
                    return a * b * c;
                }
            }
        }
    }
    return 0;
}