#include <bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
#define yes "YES"<<"\n";
#define no "NO"<<"\n";
#define en "\n"
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds; 
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
const ll MD=1000000007;
const ll N=300005;
const ll MN=-1e13+5;
const ll MX=1e13;
const ll mod1=998244353;
const ll mod=998244353;
ll _min(ll a,ll b){if(a<b)return a;return b;}
ll _abs(ll x){if(x>=0)return x;else return -x;};
ll _max(ll a,ll b){if(a>b)return a;return b;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,(a%b));}
ll lcm(ll a,ll b){ return (_max(a,b)/gcd(a,b))*_min(a,b);}
ll binex(ll a, ll b) {
    ll res = 1;
    while (b > 0){if (b & 1){res = res * a;}a = a * a;b >>= 1;}
    return res;
}
ll binpow(ll a,ll b,ll MD) {
    a%=MD;
     ll res = 1;
     while (b > 0){if (b & 1){res = res * a % MD;}a = a * a % MD;b >>= 1;}
     return res%MD;
}
void sol(){
    //write your code here
}
int main() {
	FASTIO;
	ll t;
	cin>>t;
	while(t--){
	    sol();
	}
     return 0;
}
