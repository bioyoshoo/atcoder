#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int sum = 0;
    vector<int> V;
    for (int i = 0; i < N; i++) {
        int s;
        cin >> s;
        sum += s;

        if (s % 10 != 0) V.push_back(s);
    }

    if (sum % 10 != 0) cout << sum << endl;
    else {
        if (V.size() == 0) cout << 0 << endl;
        else {
            sort(V.begin(), V.end());
            cout << sum - V.at(0) << endl;
        }
    }
}