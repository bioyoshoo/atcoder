#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> rotate(vector<string> table) {
    int n = table.size();
    vector<string> res(n, string(n, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] == '#') res[j][n - i - 1] = '#';
        }
    }
    return res;
}

vector<string> normalize(vector<string> table) {
    int n = table.size();
    int xmin = n, ymin = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] == '#') {
                xmin = min(xmin, i); ymin = min(ymin, j);
            }
        }
    }
    vector<string> res(n, string(n, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] == '#') res[i - xmin][j - ymin] = '#';
        }
    }
    return res;
}

int main() {
    int N; cin >> N;
    vector<string> S(N), T(N);
    for (int i = 0; i < N; i++) cin >> S.at(i);
    for (int i = 0; i < N; i++) cin >> T.at(i);

    bool ans = false;
    for (int i = 0; i < 4; i++) {
        if (normalize(S) == normalize(T)) ans = true;
        S = rotate(S);
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}