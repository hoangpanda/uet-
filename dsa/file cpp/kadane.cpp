#include <bits/stdc++.h>
using namespace std;

struct vv {
    int value;
    int max_3;
    int max_4;
};

vv kadane(vector<int> a, int n) {
    int ans = -1e9;
    int max_3,max_4,max_3_t;;
    for(int i = 0; i < n; ++i) ans = max(ans,a[i]);

    int t = 0;
    max_3 = 0;
    max_4 = 0;
    max_3_t = 0;
    for(int i = 0; i < n; ++i) 
        if(t + a[i] > 0) {
            t += a[i];
            if(t > ans) {
                max_4 = i;
                max_3 = max_3_t; 
                ans = t;
            }
        }
        else {
            t = 0;
            max_3_t = i + 1;
        }
    return {ans,max_3,max_4};
}

int main() {
    freopen("input.txt","r",stdin);
    int n,m; cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < m; ++j) cin >> a[i][j];

    int ans = -1e9;
    int max_1,max_2,max_3,max_4;

    /*
    1 2 
    3 4 
    */
    
    for(int i = 0; i < m; ++i) {
        vector<int> t(n,0);
        for(int j = i; j < m; ++j) {
            for(int k = 0; k < n; ++k) {
                t[k] += a[k][j];
                vv v = kadane(t,n);
                if(v.value > ans) {
                    ans = v.value;
                    max_1 = i;
                    max_2 = j;
                    max_3 = v.max_3;
                    max_4 = v.max_4;
                }
            } 
        }
    }
    cout << ans << endl;
    cout << max_1 << ' ' << max_2 << endl;
    cout << max_3 << ' ' << max_4 << endl; 
}