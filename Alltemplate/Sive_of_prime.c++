 struct sive
{
    vector<ll> pr;
    sive(ll n)
    {
         pr.resize(n+5);
        for(ll i=1;i<=n;i++)
        {
            pr[i]=i;
            if(i%2==0)pr[i]=2;
        }
        for(ll i=3;i*i<=n;i+=2)
        {
            if(pr[i]==i)
            {
                for(ll j=i*i;j<=n;j+=2*i)
                {
                    if(pr[j]==j)pr[j]=i;
                }
            }
        }
    }
    vector<ll> spf(ll m)
    {
        vector<ll> tm;
        ll i=m;
        while(pr[i]!=1)
        {
            tm.push_back(pr[i]);
            i/=pr[i];
        }
        return tm;
    }
    vector<ll> prime(ll m)
    {
        vector<ll> pm;
        for(ll i=2;i<=m;i++)
        {
            if(pr[i]==i)pm.push_back(i);
        }
        return pm;
    }
};
