#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    int64_t ans = 0;
    for (int i = 0; i < N;) {

        if (i + 1 < N && A[i] == A[i + 1]) {
            while (i + 1 < N && A[i] == A[i + 1]) i++;
        }
        
        if (i + 1 < N && A[i] <= A[i + 1]) {
            while (i + 1 < N && A[i] <= A[i + 1]) i++;
        }
        else if (i + 1 < N && A[i] >= A[i]) {
            while (i + 1 < N && A[i] >= A[i + 1]) i++;
        }

        i++;
        ans++;
    }

    cout << ans << endl;
}