#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S; cin >> S;
    int N = S.size();
    stack<pair<char, int>> sk;
    vector<pair<int, int>> ans;

    rep(i, N) {
        if (S[i] == '(') sk.push(make_pair(S[i], i + 1));
        else if (S[i] == ')') {
            ans.push_back(make_pair(sk.top().second, i + 1));
            sk.pop();
        }
    }

    for (auto [a, b]: ans) cout << a <<  " " << b << endl;
}
