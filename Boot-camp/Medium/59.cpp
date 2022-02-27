#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<char> V;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        if (i + 1 == n) V.push_back('x');
        else V.push_back('o');
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (V.at(i) == 'x') {
            ans++;
            V.at(i) = 'o';
            if (i < N - 1) V.at(i + 1) = 'o';
        }
    }

    cout << ans << endl;
}