#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    sort(A.begin(), A.end());

    int ans = 0, right = 0;
    for (int left = 0; left < N;) {
        while (right < N && A[right] - A[left] <= 2) right++;
        ans = max(ans, right - left);

        if (left == right) right++;
        int j = left + 1;
        while (A[left] == A[j]) j++;
        left = j;
    }

    cout << ans << endl;
}