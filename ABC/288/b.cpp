#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, M; cin >> N >> M;
    vector<int> L(N);
    rep(i, M) {
        int a; cin >> a; a--;
        L[a] = 1;
    }
    
    vector<int> ans;
    for (int i = 0; i < N;) {
        vector<int> v;
        if (L[i] == 1) {
            int j = i;
            while (L[j] == 1) j++;
            for (int k = j; k >= i; k--) ans.push_back(k + 1);
            
            i = j + 1;
        }
        else {
            ans.push_back(i + 1);
            i++;
        }
    }

    for (auto a: ans) cout << a << " ";
    cout << endl; 
}
