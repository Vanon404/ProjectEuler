from collections import defaultdict

def is_palindrome(n):
    return str(n) == str(n)[::-1]

count = defaultdict(int)

# Generate possible squares and cubes
max_b = 4000   # cube root bound
max_a = 100000 # square root bound

squares = [i*i for i in range(2, max_a)]
cubes = [i**3 for i in range(2, max_b)]

for a2 in squares:
    for b3 in cubes:
        n = a2 + b3
        count[n] += 1

# Filter palindromes with exactly 4 representations
palindromes = [n for n, c in count.items() if c == 4 and is_palindrome(n)]
palindromes.sort()

# Five smallest
result = sum(palindromes[:5])
print("Five smallest palindromic numbers:", palindromes[:5])
print("Sum:", result)
