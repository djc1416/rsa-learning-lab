from modules.euclidean_algorithm import gcd

def euler_totient(n):
    count = 0

    for i in range(1, n + 1):
        if gcd(i, n) == 1:
            count += 1
    return count
