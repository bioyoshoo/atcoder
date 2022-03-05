#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    
    for (auto s: S) cout << s;
    cout << endl;
}