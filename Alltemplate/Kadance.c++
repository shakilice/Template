ll maxSubarraySum(vector<ll> v,ll n) {
    ll max_so_far = 0, max_ending_here = 0;
    for (ll i = 1; i <=n; i++) {
        max_ending_here += arr[i];
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
    }
    return max_so_far;
}
