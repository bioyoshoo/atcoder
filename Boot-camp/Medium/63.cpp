#include <bits/stdc++.h>
using namespace std;

int main() {
    int W, H, N;
    cin >> W >> H >> N;
    vector<int> D = { 0, W, 0, H };
    for (int i = 0; i < N; i++) {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1) D.at(0) = max(D.at(0), x);
        else if (a == 2) D.at(1) = min(D.at(1), x);
        else if (a == 3) D.at(2) = max(D.at(2), y);
        else if (a == 4) D.at(3) = min(D.at(3), y);
    }

    cout << max(0, (D.at(1) - D.at(0))) * max(0, (D.at(3) - D.at(2))) << endl;
}