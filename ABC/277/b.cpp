#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;

    set<char> st1, st2;
    set<string> st3;
    st1.insert('H'); st1.insert('D'); st1.insert('C'); st1.insert('S'); 
    st2.insert('A'); st2.insert('T'); st2.insert('J'); st2.insert('K'); st2.insert('Q'); 
    for (int i = 2; i <= 9; i++) st2.insert((char)('0' + i));

    bool ans = true;

    rep(i, N) {
        string S; cin >> S;
        if (!st1.count(S[0])) ans = false;
        if (!st2.count(S[1])) ans = false;
        if (!st3.empty() && st3.count(S)) ans = false;

        if (ans) st3.insert(S);
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}