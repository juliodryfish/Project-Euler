#include <iostream>

bool isPalindrome(int num) {

    int reverse = 0;
    int original = num;

    auto last_number = [&num]() -> int {
        return (num % 10);
    };

    while(num > 0) {
        reverse = (reverse * 10) + last_number();

        num = num / 10;
    }

    if(reverse == original) return true;

    return false;
}

int algorithm_v2() {
    int largest = 0;
    for(int i = 999; i > 99; --i) {
        for(int k = i; k > 99; --k) {

            if(i * k  <= largest) break;

            if(isPalindrome(i * k)) {
                if( (i * k) > largest ) {
                    std::cout << i << " x "<< k << std::endl;
                    largest = (i * k);
                }
            }
        }
    }
    return largest;
}

int algorithm_v3() {
    /*
        P = 100000x * 10000y * 1000z * 100z * 10y * x 
        P = 100001x * 10010y * 1100z 
        P = 11(9091x * 910y * 100z)
    */
    int largest = 0;
    int a;
    int b;
    int dec;
    for(a = 999; a > 99; --a) {

        if( a % 11 == 0) {
            b = 999;
            dec = 1;
        } else { // b must be factor of 11 if a is not
            b = 990;
            dec = 11;
        }

        while(b >= a) {

            if(a * b  <= largest) break;

            if(isPalindrome(a * b)) {
                    std::cout << a << " x "<< b << std::endl;
                    largest = (a * b);
            }

            b = b - dec;
        }
    }

    return largest;
}



int algorithm() {
    for(int i = 999; i > 99; --i) {
        for(int k = 999; k > 99; --k) {
            if(isPalindrome(i * k)) {
                
                std::cout << i << " x "<< k << std::endl;
                
                return i * k;
            }
        }
    }
    return 0;
}



int main() {
    std::cout << algorithm() << std::endl;
    std::cout << algorithm_v2() << std::endl;
    std::cout << algorithm_v3() << std::endl;
    return 0;
}