#include<bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int table[100000][20];
void build_table(int arr[], int n) {
    for (int i=0; i<n; i++) {
        table[i][0] = arr[i];
    }
    
    int sz = (int)log2(n);
    for (int j=1; j<=sz; j++) {
        for (int i=0; i<=n-(1<<j); i++) {
            table[i][j] = __gcd(table[i][j-1], table[i+(1<<(j-1))][j-1]);
        }
    }
}

int query_table(int ql, int qr) {
    int sz = (int)log2(qr-ql+1);
    return __gcd(table[ql][sz], table[qr-(1<<sz)+1][sz]);
}

int search(int curr_gcd, int begin, int end, int i) {
    if(begin == end) return end;
    int mid = (begin+end)/2;
    if(query_table(i, mid) == curr_gcd) {
        return search(curr_gcd, mid+1, end, i);
    } else {
        return search(curr_gcd, begin, mid, i);
    }
}

void solve(int arr[], int ans[], int n) {
    build_table(arr, n);
    for(int i=0; i<n; i++) ans[i] = 1;
    
    int index, curr_gcd;
    for(int i=0; i<n; i++) {
        index = i;
        while(index < n) {
            curr_gcd = query_table(i, index);
            if(curr_gcd <= ans[n-1-i]) break;
            index = search(curr_gcd, index+1, n, i);
            ans[index-1-i] = max(curr_gcd, ans[index-1-i]);
        }
    }
    
    for(int i=n-2; i>=0; i--) {
        ans[i] = max(ans[i], ans[i+1]);
    } return;
}

int main() {
    int t, n;
	scanf("%d", &t);
	while(t--) {
        scanf("%d", &n);
        int arr[n];
        for(int i=0; i<n; i++) {
            scanf("%d", &arr[i]);
        }
        
        int ans[n];
        solve(arr, ans, n);
        
        for(int i=0; i<n; i++) {
            printf("%d ", ans[i]);
        } printf("\n");
	} return 0;
}
