#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>

//https://projecteuler.net/problem=7
int main() {
    // Solved using https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes method
    int n = 10001; // 10001th prime number

    // https://en.wikipedia.org/wiki/Prime_number_theorem
    int limit = std::ceil(n * (std::log(n) + std::log(std::log(n))));
    // upper bound for the n_th prime ^

    std::vector<int> numbers;
    numbers.resize(limit);
    std::fill(std::begin(numbers), std::end(numbers), true);

    numbers[0] = false;
    numbers[1] = false;
    for(int index = 2; index < std::sqrt(limit); ++index) {
        if(numbers[index] == true) {
            for(int p_index = index * index; p_index < limit; p_index += index) {
                numbers[p_index] = false;
            }
        }
    }
    int p_index = 0;
    for(int index = 0; index < numbers.size(); ++index) {
        if(numbers[index] == true) {
            p_index++;
            if(p_index == n) {
                p_index = index;
                break;
            }
        }
    }
    std::cout << p_index << std::endl;
    return 0;
}
