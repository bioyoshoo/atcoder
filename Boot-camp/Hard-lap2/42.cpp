#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int left = 0, right = 0;
    int head = 0, tail = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '(') left++;
        else right++;

        if (left < right) {
            right--;
            head++;
        }
    }
    tail = left - right;

    string ans = "";
    for (int i = 0; i < head; i++) ans += '(';
    ans += S;
    for (int i = 0; i < tail; i++) ans += ')';
    cout << ans << endl;
}