#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    bool flag = true;
    int pre_t = 0, pre_x = 0, pre_y = 0;
    for (int i = 0; i < N; i++) {
        int t, x, y;
        cin >> t >> x >> y;

        int dt = t - pre_t;
        int dist = abs(x - pre_x) + abs(y - pre_y);

        if (dt < dist || dt % 2 != dist % 2) flag = false;

        pre_t = t, pre_x = x, pre_y = y;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}