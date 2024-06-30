struct union_find{
    vector<ll> par;
    vector<ll> cnt;
    union_find(ll n){
        par.resize(n+5);
        cnt.resize(n+5);
        for(ll i=0;i<=n;i++){par[i]=i,cnt[i]=1;}
    }
    ll find_parent(ll u)
    {
        if(par[u]==u)return u;
        else return par[u]=find_parent(par[u]);
    }
    void marge(ll x,ll y)
    {
        ll u=find_parent(x),v=find_parent(y);
        if(x!=y)
        {
            if(cnt[x]<=cnt[y]){par[x]=y,cnt[y]+=cnt[x];}
            else{par[y]=x,cnt[x]+=cnt[y];}
        }
    }
};
