#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string s1, s2;
    cin >> s1 >> s2;

    int ans = 0;
    for (int i = 0; i <= N; i++) {
        string s3 = s1 + s2.substr(i);
        int n = s3.size();
        if (s3.substr(n - N) == s2) ans = n;
    }

    cout << ans << endl;
}