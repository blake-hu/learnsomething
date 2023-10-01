import timeit
import math
from collections import defaultdict


def disasterCode():
    # first find all primes up to sqrt(2500)
    primes = [2]
    for n in range(3, round(math.sqrt(1000)) + 1, 2):
        isPrime = True
        for p in primes:
            if n % p == 0:
                isPrime = False
                break
        if isPrime:
            primes.append(n)

    primes_by_num = defaultdict(set)

    for num in range(2, 1000):
        n = num

        for p in primes:
            if n % p == 0:
                primes_by_num[num].add(p)
                n //= p
                cached_primes = primes_by_num[n]
                primes_by_num[num] = primes_by_num[num].union(cached_primes)
                break
        else:
            primes_by_num[num].add(n)


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
