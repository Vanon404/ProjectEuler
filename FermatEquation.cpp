#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 6000000;
vector<int> primes;

void sieve() {
    vector<bool> is_prime(MAX, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAX; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (long long j = (long long)i * i; j < MAX; j += i)
                is_prime[j] = false;
        }
    }
}

unsigned long long F(int p) {
    if (p == 3) return 8;
    if (p % 3 == 2) return 0;           // Correct for primes 2 mod 3
    if (p % 3 == 1) return 1 * (p - 1) * (2 * p - 1); // Correct for primes 1 mod 3
    return 0;
}


// helper to print __int128
void print_int128(__int128 x) {
    if (x == 0) { cout << 0; return; }
    string s;
    while (x > 0) {
        s.push_back('0' + (x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    sieve();
    __int128 total = 0;
    for (int p : primes) {
        total += F(p);
    }
    print_int128(total);
    cout << endl;
    return 0;
}
