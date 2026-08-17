from modules.euclidean_algorithm import gcd

def is_prime(n):
    if n < 2:
        return False

    for divisor in range(2, n):
        if n % divisor == 0:
            return False

    return True

def euler_totient(n):
    count = 0

    for i in range(1, n + 1):
        if gcd(i, n) == 1:
            count += 1
    return count
