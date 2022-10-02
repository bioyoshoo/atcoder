#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    set<int> st;
    rep(i, N) {
        int a; cin >> a;
        st.insert(a);
    }

    int L = 0, R = N + 1;
    while (R - L > 1) {
        int x = (L + R) / 2;

        int c = 0;
        for (int i = 1; i <= x; i++) {
            if (st.count(i)) c++;
        }

        if (c + (N - c) / 2 >= x) L = x;
        else R = x;
    }
    
    cout << L << endl;
}
