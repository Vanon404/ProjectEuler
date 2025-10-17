from functools import lru_cache
from itertools import permutations
from collections import Counter

# Precompute all digit multisets (up to 13 digits) that can form a number divisible by 7
BAD_DIGIT_SETS = set()

def precompute_bad_sets(max_len=13):
    from itertools import combinations_with_replacement
    for length in range(1, max_len + 1):
        for digits in combinations_with_replacement(range(10), length):
            if digits[0] == 0:
                continue
            perms = set(permutations(digits))
            for p in perms:
                if p[0] == 0:
                    continue
                num = int(''.join(map(str, p)))
                if num % 7 == 0:
                    BAD_DIGIT_SETS.add(tuple(sorted(Counter(digits).items())))
                    break

precompute_bad_sets()

def C(N):
    digits = list(map(int, str(N)))
    L = len(digits)

    @lru_cache(None)
    def dp(pos, tight, leading_zero, digit_count):
        if pos == L:
            if leading_zero:
                return 0
            key = tuple(sorted((i, digit_count[i]) for i in range(10) if digit_count[i] > 0))
            return int(key not in BAD_DIGIT_SETS)

        limit = digits[pos] if tight else 9
        total = 0

        for d in range(0, limit + 1):
            ntight = tight and (d == limit)
            nleading = leading_zero and d == 0
            ndigit_count = list(digit_count)
            if not nleading:
                ndigit_count[d] += 1
            total += dp(pos + 1, ntight, nleading, tuple(ndigit_count))
        return total

    return dp(0, True, True, tuple([0] * 10))

# Run tests
if __name__ == "__main__":
    print("C(100) =", C(100))         # ✅ Expected: 74
    print("C(10**4) =", C(10**4))     # ✅ Expected: 3737
    print("C(10**13) =", C(10**13))   # ✅ Expected: 1861342176