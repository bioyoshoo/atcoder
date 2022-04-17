#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    set<int> num;
    for (int i = 0; i <= 9; i++) num.insert(i);
    for (char i: s) num.erase(i - '0');

    for (int c: num) cout << c << endl;
}