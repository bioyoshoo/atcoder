#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;

    string ans = "";
    while (N != 0) {
        if (N % 2 != 0) {
            ans = '1' + ans;
            N--;
        }
        else ans = '0' + ans;
        N /= (-2);
    }

    if (ans == "") ans = '0';
    cout << ans << endl;
}