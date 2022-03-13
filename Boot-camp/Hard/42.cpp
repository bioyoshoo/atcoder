#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int left = 0, right = 0;
    int add_left = 0, add_right = 0;
    for (int i = 0; i < N; i++) {
        if (S.at(i) == '(') left++;
        else if (S.at(i) == ')') right++;

        if (left < right) {
            add_left++;
            right--;
        }
    }
    add_right = left - right;

    string ans = "";
    for (int i = 0; i < add_left; i++) ans += '(';
    ans += S;
    for (int i = 0; i < add_right; i++) ans += ')';

    cout << ans << endl;
}