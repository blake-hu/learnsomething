import timeit
import math
from collections import defaultdict


def disasterCode():
    all_primes = set()
    primes_by_num = defaultdict(set)

    for num in range(2, 1000):

        upper = round(math.sqrt(num)) + 1
        for factor in range(2, upper):

            if num % factor != 0 or factor % 2 == 0:
                # num is not a multiple of factor
                continue

            if factor in all_primes:
                # factor is a prime factor of num
                primes_by_num[num].add(factor)
                continue

            if isPrime(factor):
                all_primes.add(factor)
                primes_by_num[num].add(factor)


def isPrime(num):
    upper = round(math.sqrt(num)) + 1
    prime = True

    for i in range(3, upper, 2):
        if (num % i == 0):
            prime = False
            break

    return prime


# Benchmark the code
if __name__ == "__main__":
    benchmark_code = "disasterCode()"
    setup_code = "from __main__ import disasterCode"

    # Measure the execution time of disasterCode function
    times = []
    for i in range(0, 5):
        times.append(timeit.timeit(benchmark_code, setup=setup_code, number=1))

    res = sum(times) / 5

    print(f"Average execution time after 5 runs: {res:.6f} seconds")
