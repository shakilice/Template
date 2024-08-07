ll fac[N+5],inf[N+5];
void fac_call()
{
    fac[0]=1;
    fac[1]=1;
    inf[0]=binpow(1,mod-2,mod);
    inf[1]=binpow(1,mod-2,mod);
    for(ll i=1;i<=N;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
        inf[i]=binpow(fac[i],mod-2,mod);
    }
}
ll ncr(ll n,ll r)
{
    if(r>n)return 0;
    ll a=(fac[n]*inf[r])%mod;
    a=(a*inf[n-r])%mod;
    return a;
}
