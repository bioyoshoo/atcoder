#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;

    vector<string> V(N);
    int query;
    string s;
    int left = 0, right = N - 1;
    rep(i, 20) {
        // output
        if (i == 0) query = 0;
        else if (i == 1) query = N - 1;
        else query = (left + right) / 2;
        cout << query << endl;

        // input
        cin >> s;
        if (s == "Vacant") break;
        V[query] = s;

        if (i > 1) {
            int d = query - left;
            if (d % 2 == 0 && V[left] == V[query]) left = query;
            else if (d % 2 == 1 && V[left] != V[query]) left = query;
            else right = query;
        }
    }
}