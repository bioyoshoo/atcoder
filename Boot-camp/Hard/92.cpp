#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> V(N, 0);
    for (int64_t i = 0; i < M; i++) {
        int64_t a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a]++;
        V[b]++;
    }

    bool flag = true;
    for (int i = 0; i <= N; i++) if (V[i] % 2 == 1) flag = false;

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}