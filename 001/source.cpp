#include <iostream>


/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/


int algorithm_v1(int it) {
    int counter = 0;
    for(int i = 1; i < it; ++i) {
        if(i % 3 == 0) counter += i;
        else if( i % 5 == 0) counter += i;
    }
    return counter;
}

int algorithm_v2(int lim = 1000) {
    
    // using the sum of linear progression formulae
    // much more elegant and efficient

    /*
    
        sum = (n (A1 + An)) / 2

        An = A1 + (n - 1).d

        n = An / d    
    
    */

    auto an = [](int a1, int n, int d) {
        return a1 + ( (n - 1) * d );
    };

    auto sum = [&an](int a1, int n, int d) {
        return ( n * (a1 + an(a1, n, d)) ) / 2;
    };
    
    auto n = [](int an, int d) -> int {
        return static_cast<int>(an / d);
    };

    return (
        
        sum(3, n(999,3), 3) + 
        sum(5, n(999,5), 5) - 
        sum(15, n(999,15), 15)  
    );
}


int main() {
    //std::cout << algorithm(10) << std::endl;

    int r = 999 / 5;
    std::cout << r << std::endl;


    std::cout << algorithm(1000) << std::endl;
    std::cout << func() << std::endl;
    return 0;
}