/*This code return min,max and sum
and work only increase or decrease valu of arange */
struct node{
    ll mn,mx,sum,lz_v;
    node()
    {mn=0;mx=0;sum=0;lz_v=0;}
};
typedef struct q_ans{ll mn,mx,sum;}qn;
class ST{
    public:
    vector<node> tree;
    //tree  size initialization
    ll sz;
    ST(ll x){tree.resize(x*4);sz=x;}
    //built the tree
    void _creat(vector<ll> &v,ll pr,ll lt,ll rt)
    {
        if(lt==rt)
        {
            tree[pr].mn=v[lt],tree[pr].mx=v[lt],tree[pr].sum=v[lt];return;
        }
        ll left_node=pr*2,mid=(lt+rt)/2,right_node=pr*2+1;
        _creat(v,left_node,lt,mid);
        _creat(v,right_node,mid+1,rt);
        tree[pr].mn=_min(tree[left_node].mn,tree[right_node].mn);
        tree[pr].mx=_max(tree[left_node].mx,tree[right_node].mx);
        tree[pr].sum=tree[left_node].sum+tree[right_node].sum;
    }
    void creat(vector<ll> &v)
    {
        _creat(v,1,1,sz);
    }
    //updaed on the tree
    void _update(ll pr,ll trl,ll trr,ll upl,ll upr,ll valu)
    {
        if(trl>=upl&&trr<=upr){tree[pr].lz_v=tree[pr].lz_v+valu;return;}
        if(trl>upr||trr<upl)return;
        ll mid=(trl+trr)/2,left_node=pr*2,right_node=pr*2+1;
        tree[left_node].lz_v=tree[pr].lz_v+tree[left_node].lz_v;
        tree[right_node].lz_v=tree[pr].lz_v+tree[right_node].lz_v;
        tree[pr].lz_v=0;
        _update(left_node,trl,mid,upl,upr,valu);
        _update(right_node,mid+1,trr,upl,upr,valu);
        tree[pr].sum=tree[left_node].sum+(tree[left_node].lz_v*(mid-trl+1))+tree[right_node].sum+tree[right_node].lz_v*(trr-mid);
        tree[pr].mn=_min(tree[left_node].mn+tree[left_node].lz_v,tree[right_node].mn+tree[right_node].lz_v);
        tree[pr].mx=_max(tree[left_node].mx+tree[left_node].lz_v,tree[right_node].mx+tree[right_node].lz_v);
    }
    void update(ll l,ll r,ll valu)
    {
        _update(1,1,sz,l,r,valu);
    }
    // quary on tree
    qn _quary(ll pr,ll trl,ll trr,ll ql,ll qr,ll cary)
    {
        if(trl>qr||trr<ql)
        {
            qn nd;nd.mn=MX,nd.mx=MN,nd.sum=0;return nd;
        }
        if(trl>=ql&&trr<=qr)
        {  qn nd;
            nd.mn=tree[pr].mn+cary+tree[pr].lz_v;
            nd.mx=tree[pr].mx+cary+tree[pr].lz_v;
            nd.sum=tree[pr].sum+(cary+tree[pr].lz_v)*(trr-trl+1);
            return nd;
        }
        ll mid=(trl+trr)/2,left_node=pr*2,right_node=pr*2+1;
        cary+=tree[pr].lz_v;
        qn a,b,c;
        a=_quary(left_node,trl,mid,ql,qr,cary);
        b=_quary(right_node,mid+1,trr,ql,qr,cary);
        c.mn=_min(a.mn,b.mn),c.mx=_max(a.mx,b.mx),c.sum=a.sum+b.sum;return c;
    }
    qn quary(ll l,ll r)
    {
        qn a=_quary(1,1,sz,l,r,0);
        return a;
    }
};
