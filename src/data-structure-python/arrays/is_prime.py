def is_prime_while(n):
    divisor = 2
    while divisor < n:
        if n % divisor == 0:
            return False
        divisor += 1
    return True

def is_prime_for(n):
    for divisor in range(2, n):
        if n % divisor == 0:
            return False
    return True

# Sieve of Eratothenes
def print_primes(n):
    prime = [True] * (n+1)
    p = 2
    while p * p <= n:
        if prime[p]:
            for i in range(p * p, n + 1, p):
                prime[i] = False 
        p += 1
    
    for p in range(2, n + 1):
        if prime[p]:
            print(p)

if __name__ == "__main__":
    print_primes(20)