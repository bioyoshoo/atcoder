#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    long long ans = 0;
    for (int i = 0; i < N;) {
        if (A[i] != 0) {
            int j = i;
            long long sum = 0;
            while (j < N && A[j] != 0) {
                sum += A[j];
                j++;
            }
            ans += sum / 2;
            i = j;
        }
        else i++;
    }
    cout << ans << endl;
}