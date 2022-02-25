#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<string, int> DB;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;

        sort(S.begin(), S.end());

        if (DB.count(S)) DB.at(S)++;
        else DB[S] = 1;
    }

    int64_t ans = 0;
    for (auto db: DB) ans += (db.second) * (db.second - 1) / 2;

    cout << ans << endl;
}