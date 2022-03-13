#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    stack<char> sk;
    for (auto s: S) {
        if (!sk.empty() && sk.top() == 'S' && s == 'T') sk.pop();
        else sk.push(s);
    }

    cout << sk.size() << endl;
}