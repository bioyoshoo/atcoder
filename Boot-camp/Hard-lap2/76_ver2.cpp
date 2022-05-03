#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = (int)S.size();

    long long ans = 0;
    for (long long i = 0; i < (1LL << (N - 1)); i++) {
        long long sum = 0;
        for (int j = 0; j < N - 1; j++) {
            sum = 10 * sum + (int)(S.at(j) - '0');
            if (i & (1LL << j)) {
                ans += sum;
                sum = 0;
            }
        }
        sum = 10 * sum + (int)(S.at(N - 1) - '0');
        ans += sum;
    }
    cout << ans << endl;
}