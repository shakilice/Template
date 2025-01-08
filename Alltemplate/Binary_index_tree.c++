//use for only sum and point updat rage quary
//range update point quary and only increase or decrease a valu
struct BIT {
    vector<ll> bitree; 
    ll bit_length;             
    BIT(ll bit_size) {
        bit_length = bit_size; bitree.resize(bit_length + 5, 0);
    }
    void update(ll idx, ll val) {
        while (idx <=bit_length) {
            bitree[idx] += val;
            idx += idx & -idx;
        }
    }
    ll _query(ll idx) {
        ll sum = 0;
        while (idx > 0) {
            sum += bitree[idx];
            idx -= idx & -idx; 
        }
        return sum;
    }
    ll query(ll l, ll r) {
        return _query(r) - _query(l - 1);
    }
};
