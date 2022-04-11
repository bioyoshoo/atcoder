#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        mp[a % 4]++;
    }
    
    string ans = "";
    if (mp[0] == 0) {
        if (mp[2] == N) ans = "Yes";
        else ans = "No";
    }
    else if (mp[0] > 0 && mp[2] > 0) {
        if (mp[0] >= mp[1] + mp[3]) ans = "Yes";
        else ans = "No";
    }
    else if (mp[0] > 0 && mp[2] == 0) {
        if (mp[0] >= mp[1] + mp[3] - 1) ans = "Yes";
        else ans = "No";
    }

    cout << ans << endl;
}