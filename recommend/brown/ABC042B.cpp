#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    vector<string> V;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        V.push_back(s);
    }

    sort(V.begin(), V.end());

    string ans = "";
    for (int i = 0; i < N; i++) ans += V.at(i);
    cout << ans << endl;
}