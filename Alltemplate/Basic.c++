//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<math.h>
#include<stack>
#include<queue>
#include<deque>
#define int long long int
#define ff first
#define ss second
#include<bitset>
const int MD=1e9+7;
const int MX =1e18;
const int MN=-1e18;
using namespace std;
int _min(int a,int b){if(a<b)return a;return b;}
int _max(int a,int b){if(a>b)return a;return b;}
int gcd(int a,int b){if(b==0)return a;return gcd(b,(a%b));}
int binex(int a, int b) {
    int res = 1;
    while (b > 0){if (b & 1){res = res * a;}a = a * a;b >>= 1;}
    return res;
}
int binpow( int a,int b, int MD) {
    a %=MD;
    int res = 1;
    while (b > 0){if (b & 1){res = res * a % MD;}a = a * a % MD;b >>= 1;}
    return res;
}
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds; 
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
void sol()
{
    return;
}
int32_t main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
        sol();
    }
       return 0;
}
