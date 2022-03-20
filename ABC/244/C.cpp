#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> remain;
    for (int n = 1; n <= 2 * N + 1; n++) remain.insert(n);
    
    for (int ans: remain) {
        cout << ans << endl;
        remain.erase(ans);
        break;
    }

    while (true) {
        int enemy;
        cin >> enemy;

        if (enemy == 0) break;

        remain.erase(enemy);

        for (int ans: remain) {
            cout << ans << endl;
            remain.erase(ans);
            break;
        }
    }
}