/*This code return min,max and sum
and work only increase or decrease valu of arange */
struct node{
    int mn,mx,sum,lz_v;
    node()
    {mn=0;mx=0;sum=0;lz_v=0;}
};
typedef struct q_ans{int mn,mx,sum;}qn;
class ST{
    public:
    vector<node> tree;
    int _min(int a,int b){if(a<b)return a;return b;}
    int _max(int a,int b){if(a>b)return a;return b;}
    //tree  size initialization
    ST(int x){tree.resize(x);}
    //built the tree
    void creat(vector<int> &v,int pr,int lt,int rt)
    {
        if(lt==rt)
        {
            tree[pr].mn=v[lt],tree[pr].mx=v[lt],tree[pr].sum=v[lt];return;
        }
        int left_node=pr*2,mid=(lt+rt)/2,right_node=pr*2+1;
        creat(v,left_node,lt,mid);
        creat(v,right_node,mid+1,rt);
        tree[pr].mn=_min(tree[left_node].mn,tree[right_node].mn);
        tree[pr].mx=_max(tree[left_node].mx,tree[right_node].mx);
        tree[pr].sum=tree[left_node].sum+tree[right_node].sum;
    }
    //updaed on the tree
    void update(int pr,int trl,int trr,int upl,int upr,int valu)
    {
        if(trl>=upl&&trr<=upr){tree[pr].lz_v=tree[pr].lz_v+valu;return;}
        if(trl>upr||trr<upl)return;
        int mid=(trl+trr)/2,left_node=pr*2,right_node=pr*2+1;
        tree[left_node].lz_v=tree[pr].lz_v+tree[left_node].lz_v;
        tree[right_node].lz_v=tree[pr].lz_v+tree[right_node].lz_v;
        tree[pr].lz_v=0;
        update(left_node,trl,mid,upl,upr,valu);
        update(right_node,mid+1,trr,upl,upr,valu);
        tree[pr].sum=tree[left_node].sum+(tree[left_node].lz_v*(mid-trl+1))+tree[right_node].sum+tree[right_node].lz_v*(trr-mid);
        tree[pr].mn=_min(tree[left_node].mn+tree[left_node].lz_v,tree[right_node].mn+tree[right_node].lz_v);
        tree[pr].mx=_max(tree[left_node].mx+tree[left_node].lz_v,tree[right_node].mx+tree[right_node].lz_v);
    }
    // quary on tree
    qn quary(int pr,int trl,int trr,int ql,int qr,int cary)
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
        int mid=(trl+trr)/2,left_node=pr*2,right_node=pr*2+1;
        cary+=tree[pr].lz_v;
        qn a,b,c;
        a=quary(left_node,trl,mid,ql,qr,cary);
        b=quary(right_node,mid+1,trr,ql,qr,cary);
        c.mn=_min(a.mn,b.mn),c.mx=_max(a.mx,b.mx),c.sum=a.sum+b.sum;return c;
    }
};
