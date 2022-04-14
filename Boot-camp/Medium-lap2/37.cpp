#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H.at(i);

    int ans = 0;
    while (true) {
        
        int right = 0;
        for (int left = 0; left < N;) {
            while (right < N && H[right] != 0) {
                H[right]--;
                right++;
            }
            if (right - left > 0) ans++;

            if (right == left) right++;
            left = right;
        }

        bool flag = true;
        for (int i = 0; i < N; i++) {
            if (H[i] != 0) flag = false;
        }

        if (flag) break;
    }

    cout << ans << endl;
}