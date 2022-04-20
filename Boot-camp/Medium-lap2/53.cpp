#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    
    vector<int64_t> A;
    A.push_back(0);
    for (int i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        A.push_back(a);
    }
    A.push_back(0);

    int64_t total = 0;
    for (int i = 1; i < N + 2; i++) total += abs(A[i] - A[i - 1]);
    
    int64_t ans;
    for (int i = 1; i < N + 1; i++) {
        ans = total - abs(A[i] - A[i - 1]) - abs(A[i + 1] - A[i]) + abs(A[i + 1] - A[i - 1]);
        cout << ans << endl;
    }
}