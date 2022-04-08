#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N), diff;
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int i = 0; i < N - 1; i++) {
        if (A.at(i + 1) - A.at(i) == 0) continue;

        if (A.at(i + 1) - A.at(i) > 0) diff.push_back(1);
        else diff.push_back(-1);
    }
    int n = diff.size();
    
    int right = 0;
    int ans = 0;
    for (int left = 0; left < n;) {
        
        while (diff[left] == diff[right] && right < n) right++;
        ans += 1;

        if (left == right) right++;
        left = right;
    }

    cout << ans << endl;
}