n = 1000000
primes = [0] * n 
result = 2
#result: 142913828922

#attempt at optimising sieve of Eratosthenes
for i in range(1, n):
    if primes[i] == 0:
        inc = (2*i) + 1
        result += (2 * i) + 1
        for k in range(i+inc, n, +inc):
            primes[k] = 1

print(result)