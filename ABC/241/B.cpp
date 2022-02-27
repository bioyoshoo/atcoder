#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> Pasta(N);
    for (int i = 0; i < N; i++) cin >> Pasta.at(i);

    bool ans = true;
    for (int i = 0; i < M; i++) {
        int m;
        cin >> m;
        bool flag = false;
        for (int i = 0; i < N; i++) {
            if (Pasta.at(i) == m) {
                Pasta.at(i) = -1;
                flag = true;
                break;
            }
        }
        if (!flag) {
            ans = false;
            break;
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}