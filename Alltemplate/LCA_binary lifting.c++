/*
This code Find,kth ancestor,LCA,depth,parent any type
of tree and any roote mention.This code aslo be use binay lifting.
 */
struct LCA{
    vector< vector<ll> > pr;
    vector<ll> dapth;
    ll root,sz,lz;
    LCA(vector<vector<ll> >&tm,ll rt)
    {
        sz=tm.size(),root=rt;
        lz=log2(sz)+5;
        pr.resize(sz+5,vector<ll>(lz+5));
        for(ll i=0;i<=lz;i++)pr[root][i]=root;
        dapth.resize(sz+5);
        stack<ll> st;
        st.push(root);
        dapth[root]=0;
        while(!st.empty())
        {
            ll x=st.top();st.pop();
            ll f=tm[x].size();
            for(ll i=0;i<f;i++)
            {ll child=tm[x][i];
                if(child!=pr[x][0])
                {dapth[child]=dapth[x]+1;
                    pr[child][0]=x;
                    st.push(child);
                }
            }
        }
        for(ll i=1;i<=lz;i++){
        for(ll j=1;j<=sz;j++){
            pr[j][i]=pr[pr[j][i-1]][i-1];}
         }
    }
    ll parent(ll u,ll k)
    {for(ll i=lz;i>=0;i--)
        {if((k&(1<<i)))
            {u=pr[u][i];}
        }return u;
    }
    ll lca(ll u,ll v)
    {ll d1=dapth[u],d2=dapth[v];
        if(d1>d2)
        {u=parent(u,d1-d2);}
        if(d2>d1)
        {v=parent(v,d2-d1);}
        if(u==v)return u;
        for(ll i=lz;i>=0;i--)
        {
            ll x=pr[u][i];
            ll y=pr[v][i];
            if(x!=y)
            {
                u=x,v=y;
            }
        }
        return pr[u][0];
    }
};
