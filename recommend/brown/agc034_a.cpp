#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(string S) {
    bool res = true;
    int n = S.size();
    for (int i = 0; i < n; i++) {
        if (S.substr(i, 2) == "##") res = false;
    }
    return res;
}

bool check2(string S) {
    bool res = false;
    int n = S.size();
    for (int i = 0; i < n; i++) {
        if (S.substr(i, 3) == "...") res = true;
    }
    return res;
}

int main() {
    int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
    string S; cin >> S;

    bool ans = true;
    string sub_A = S.substr(A - 1, C - A + 1), sub_B = S.substr(B - 1, D - B + 1);
    if (!check(sub_A)) ans = false;
    if (!check(sub_B)) ans = false;
    if (D < C) {
        string sub_C = S.substr(B - 2, D - B + 3);
        if (!check2(sub_C)) ans = false;
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}