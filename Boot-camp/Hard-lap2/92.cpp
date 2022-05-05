#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> path(N, 0);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        if (a == 0) path[b]++;
        else if (b == 0) path[a]++;
        else path[a]++, path[b]++;
    }
    bool flag = true;
    for (int i = 0; i < N; i++) if (path[i] % 2 != 0) flag = false;
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}