#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<bool> seen(N, false);
    vector<int> num(N, 1);
    seen[0] = true;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        num[x]--;
        num[y]++;
        if (seen[x]) seen[y] = true;
        if (num[x] == 0) seen[x] = false;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (seen[i]) ans++;
    }

    cout << ans << endl;
}