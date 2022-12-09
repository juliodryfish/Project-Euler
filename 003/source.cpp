#include <iostream>

bool isPrime(long long int n) {
    for(long long int i = 2; i < n; ++i) {
        if(n % i == 0) return false;
    }

    return true;
}


long long int algorithm(long long int goal) {
    long long int max = 0;
    for(long long int i = 1; i < goal / 4; ++i) {
        if(goal % i == 0)  {
            if(isPrime(i)) max = i;
        }
    }
    return max;
}



int main() {
    std::cout << algorithm(600851475143) << std::endl;


    return 0;
}