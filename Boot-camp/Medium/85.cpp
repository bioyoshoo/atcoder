#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, int> M;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        M[a]++;
    }

    bool ans = false;
    if (N % 3 != 0) {
        if (M[0] == N) ans = true;
    }
    else  {
        vector<int> V;
        for (auto m: M) V.push_back(m.first);

        if (V.size() == 1 && M[0] == N) ans = true;
        else if (V.size() == 2 && M[0] == N / 3) ans = true;
        else if (V.size() == 3) {
            bool cond1, cond2;
            cond1 = (V.at(0) ^ V.at(1) ^ V.at(2)) == 0;
            cond2 = (M.at(V.at(0)) == N / 3) && (M.at(V.at(1)) == N / 3) && (M.at(V.at(2)) == N / 3);
            if (cond1 && cond2) ans = true;
        }
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
