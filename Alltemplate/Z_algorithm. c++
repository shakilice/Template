//custom Z_function in string
struct z_func{
    vector<ll> Z;
    z_func(string s) {
    ll  n = s.size();Z.resize(n+5);
    ll l =0, r =0;
    for(int i = 1; i <n; i++) {
        if(i < r) {
            Z[i] = min(r - i, Z[i - l]);
        }
        while(i + Z[i] <n && s[Z[i]] == s[i + Z[i]]) {
            Z[i]++;
        }
        if(i + Z[i] > r) {
            l = i;
            r = i + Z[i];
        }
    }
   }
    //use for index valu 1 besed
    ll ind_z(ll c){
        return Z[c-1];
    }
    //use for z function arry 1 besed
    vector<ll> z_arry()
    {
        ll sz=Z.size();
      vector<ll> d(sz+5);
      for(ll i=1;i<=sz;i++)d[i]=Z[i-1];
        return d;
    }
};
