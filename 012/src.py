#optimised using: https://www.math.uh.edu/~minru/web/divis2.html

g = 500  
n = 0
increment = 1
while True:
    n = n + increment
    #print("\r",n, end="")
    l = int(n**0.5)
    divisors = 0
    for i in range(1,l+1):
        if n % i == 0:
            divisors = divisors + 1
            if i * int(n/i) > i:
                divisors = divisors + 1
    if divisors > g:
        print("divisors=",divisors)
        print("n=",n)
        break
    increment = increment + 1