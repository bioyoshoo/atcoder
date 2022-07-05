#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S; cin >> S;
    int N = S.size();
    int K; cin >> K;

    set<string> st;
    rep(i, N) {
        for (int j = i; j < i + 5; j++) {
            st.insert(S.substr(i, j - i + 1));
        }
    }
    vector<string> V;
    for (auto s: st) V.push_back(s);
    sort(V.begin(), V.end());
    cout << V[K - 1] << endl;
}