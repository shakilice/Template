/*
  cnt[k]= how many number that divisible by k;
  g[k]=number of tuple that that have divisor of k;
  f[k]=number of tuple that have gcd k;
  // g[k]=cnt[k]^t if unordered and t is the  touple;
  // g[k]=cnt[k]Ct if order and non repetative
  // g[k]=cnt[k]+t-1Ct order and repetative
  Remainder given solution is based on the subset not touple
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

long long modpow(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    vector<int> freq(n+1, 0);
    for (int x : a) freq[x]++;

    vector<int> cnt(n+1, 0);
    // Count how many numbers divisible by k
    for (int k = 1; k <= n; k++) {
        for (int multiple = k; multiple <= n; multiple += k) {
            cnt[k] += freq[multiple];
        }
    }

    vector<long long> g(n+1, 0), f(n+1, 0);
    for (int k = 1; k <= n; k++) {
        if (cnt[k] > 0)
            g[k] = (modpow(2, cnt[k], MOD) - 1 + MOD) % MOD;
    }

    // Inclusion-exclusion from largest down
    for (int k = n; k >= 1; k--) {
        long long val = g[k];
        for (int multiple = 2*k; multiple <= n; multiple += k) {
            val -= f[multiple];
            if (val < 0) val += MOD;
        }
        f[k] = val;
    }

    for (int k = 1; k <= n; k++) {
        cout << f[k] << " ";
    }
    cout << "\n";
}
