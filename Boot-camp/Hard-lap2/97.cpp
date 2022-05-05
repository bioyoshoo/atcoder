#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;

    if (N != 0) {
        vector<int> ans;
        while (N != 0) {
            int r = N % (-2);
            if (r < 0) r += 2;
            if (r != 0) {
                ans.push_back(1);
                N -= r;
            }
            else ans.push_back(0);
            N /= -2;
        }
        reverse(ans.begin(), ans.end());
        for (auto a: ans) cout << a;
        cout << endl;
    }
    else cout << 0 << endl;
}