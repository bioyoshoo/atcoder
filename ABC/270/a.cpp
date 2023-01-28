#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

set<int> check(int n) {
    set<int> st;
    if (n == 0) return st;
    else if (n == 1) {
        st.insert(0);
    }
    else if (n == 2) {
        st.insert(1);
    }
    else if (n == 3) {
        st.insert(0);
        st.insert(1);
    }
    else if (n == 4) {
        st.insert(2);
    }
    else if (n == 5) {
        st.insert(0);
        st.insert(2);
    }
    else if (n == 6) {
        st.insert(1);
        st.insert(2);
    }
    else if (n == 7) {
        st.insert(0);
        st.insert(1);
        st.insert(2);
    }
    return st;
}

int main() {
    int A, B;
    cin >> A >> B;

    set<int> st_a = check(A), st_b = check(B);

    int ans = 0;
    rep(i, 3) {
        if (st_a.count(i) || st_b.count(i)) ans += pow(2, i);
    }

    cout << ans << endl;
}