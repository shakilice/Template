 /*This code only return sum and
 work both set and range update.
 Zero based index arry creat tree
 */
struct SegTree {
    struct Node {
        Node* left;
        Node* right;
        ll l, r, sum;
        ll lazy_set = -1, lazy_sum = 0;
        ll get_m() { return (l+r)/2; }
        ll size() { return r-l+1; }
    };
 
    Node* root;
    vector<ll>& arr;
 
    SegTree (vector<ll>& a) : arr(a) {
        root = new Node;
        root->l = 0;
        root->r = a.size()-1;
        build(root);
    }
 
    void build(Node* node) {
        if (node->l == node->r) {
            node->sum = arr[node->l];
            return;
        }
 
        node->left = new Node;
        node->left->l = node->l;
        node->left->r = node->get_m();
        build(node->left);
 
        node->right = new Node;
        node->right->l = node->get_m()+1;
        node->right->r = node->r;
        build(node->right);
 
        node->sum = node->left->sum + node->right->sum;
    }
 
    void push(Node* node) {
        if (node->lazy_set != -1 || node->lazy_sum > 0) {
            if (node->lazy_set != -1) {
                node->left->sum = node->left->size()*node->lazy_set;
                node->left->lazy_set = node->lazy_set;
                node->left->lazy_sum = 0;
 
                node->right->sum = node->right->size()*node->lazy_set;
                node->right->lazy_set = node->lazy_set;
                node->right->lazy_sum = 0;
 
                node->lazy_set = -1;
            }
 
            node->left->sum += node->left->size()*node->lazy_sum;
            node->left->lazy_sum += node->lazy_sum;
            node->right->sum += node->right->size()*node->lazy_sum;
            node->right->lazy_sum += node->lazy_sum;
            node->lazy_sum = 0;
        }
    }
 
    void update(Node* node, ll l, ll r, ll delta) {
        if (node->l == l && node->r == r) {
            node->sum += node->size()*delta;
            node->lazy_sum += delta;
            return;
        }
 
        push(node);
        if (l <= node->get_m())
            update(node->left, l, min(r, node->get_m()), delta);
        if (node->get_m() < r)
            update(node->right, max(l, node->get_m()+1), r, delta);
 
        node->sum = node->left->sum + node->right->sum;
    }
 
    void update_set (Node* node, ll l, ll r, ll x) {
        if (node->l == l && node->r == r) {
            node->sum = node->size()*x;
            node->lazy_set = x;
            node->lazy_sum = 0;
            return;
        }
 
        push(node);
        if (l <= node->get_m())
            update_set(node->left, l, min(r, node->get_m()), x);
        if (node->get_m() < r)
            update_set(node->right, max(l, node->get_m()+1), r, x);
 
        node->sum = node->left->sum + node->right->sum;
    }
 
    void update(ll l, ll r, ll delta) { update(root, l, r, delta); }
    void update_set(ll l, ll r, ll x) { update_set(root, l, r, x); }
 
    ll query(Node* node, ll l, ll r) {
        if (node->l == l && node->r == r) 
            return node->sum;
        
        push(node);
        ll ans = 0;
        if (l <= node->get_m())
            ans += query(node->left, l, min(r, node->get_m()));
        if (node->get_m() < r)
            ans += query(node->right, max(l, node->get_m()+1), r);
        return ans;
    }
 
    ll query(ll l, ll r) { return query(root, l, r); }
};
