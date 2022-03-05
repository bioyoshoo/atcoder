#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> num(N, 1);
    vector<bool> prob(N, false);
    prob.at(0) = true;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        if (prob.at(x - 1)) prob.at(y - 1) = true;
        num.at(x - 1)--;
        if (num.at(x - 1) == 0) prob.at(x - 1) = false;
        num.at(y - 1)++;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (prob.at(i) && num.at(i) > 0) ans++;
    }

    cout << ans << endl;
}