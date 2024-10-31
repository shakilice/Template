//use mode for particular use
// 1 based index arry use
enum QueryType {g, mn,mx};
struct SparseTable {
    vector<vector<ll>> table;
    vector<ll> logTable;
    ll n; QueryType mode;
    SparseTable(const vector<ll>& arr, QueryType queryType) {
        n = arr.size();
        ll maxLog = log2(n) + 5;
        mode = queryType;
        table.resize(n + 5, vector<ll>(maxLog));
        logTable.resize(n + 5);
        for (ll i = 2; i <= n; i++){
            logTable[i] = logTable[i / 2] + 1;
        }
        for (ll i = 1; i <= n; i++) {
            table[i][0] = arr[i];
        }
        for (ll j = 1; j < maxLog; j++) {
            for (ll i = 1; i + (1 << j) - 1 <= n; i++) {
                if (mode == GCD) {
                    table[i][j] = gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
                } else if (mode == MIN) {
                    table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
                } else if (mode == MAX) {
                    table[i][j] = max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
                }
            }
        }
    }
    ll query(ll L, ll R) {
        ll j = logTable[R - L + 1];
        if (mode == GCD) {
            return gcd(table[L][j], table[R - (1 << j) + 1][j]);
        } else if (mode == MIN) {
            return min(table[L][j], table[R - (1 << j) + 1][j]);
        } else if (mode == MAX) {
            return max(table[L][j], table[R - (1 << j) + 1][j]);
        }
        return -1;
    }
    ll gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
