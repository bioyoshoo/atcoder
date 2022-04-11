#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    deque<char> dq;

    for (char c: s) {
        if (c != 'B') dq.push_back(c);
        else {
            if (dq.size() > 0) dq.pop_back();
        }
    }

    while (dq.size() > 0) {
        cout << dq.front();
        dq.pop_front();
    }
    cout << endl;
}