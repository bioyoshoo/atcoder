#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int64_t, int>> height(N);
    for (int i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        height.at(i) = {a, i + 1};
    }

    sort(height.rbegin(), height.rend());

    for (int i = 0; i < N; i++) cout << height.at(i).second << endl;
}