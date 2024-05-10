//Hasing use for custom
// 1 base index
const ll MOD1 = 127657753, MOD2 = 987654319;
const ll p1 = 257, p2 = 277;
ll ip1, ip2;
pair<ll, ll> pw[N], ipw[N];
void precall() {
    pw[0] =  {1, 1};
    for (ll i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i - 1].first * p1 % MOD1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % MOD2;
    }
    ip1 = binpow(p1, MOD1 - 2, MOD1);
    ip2 = binpow(p2, MOD2 - 2, MOD2);
    ipw[0] =  {1, 1};
    for (ll i = 1; i < N; i++) {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % MOD1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % MOD2;
    }

}
struct Hashing {
    ll n;
    vector<pair<ll, ll> > hs; // 1 - indexed
    Hashing() {}
    Hashing(const string& s) {
        n = s.size();
        hs.emplace_back(0, 0);
        for (ll i = 0; i < n; i++) {
            pair<ll, ll> p;
            p.first = (hs[i].first + 1LL * pw[i].first * s[i] % MOD1) % MOD1;
            p.second = (hs[i].second + 1LL * pw[i].second * s[i] % MOD2) % MOD2;
            hs.push_back(p);
        }
    }
    pair<ll, ll> get_hash(ll l, ll r) { // 1 - indexed
       // assert(1 <= l && l <= r && r <= n);
        pair<ll, ll> ans;
        ans.first = (hs[r].first - hs[l - 1].first + MOD1) * 1LL * ipw[l - 1].first % MOD1;
        ans.second = (hs[r].second - hs[l - 1].second + MOD2) * 1LL * ipw[l - 1].second % MOD2;
        return ans;
    }
    pair<ll, ll> get_hash() {
        return get_hash(1, n);
    }
};
