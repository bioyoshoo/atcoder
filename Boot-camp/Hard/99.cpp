#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    int64_t ans = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        if (A.at(i) == 0) {
            ans += sum / 2;
            sum = 0;
        }
        else sum += A.at(i);
    }
    ans += sum / 2;
    
    cout << ans << endl;
}