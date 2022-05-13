#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int N = S.size();

    int rev_cnt = 0;
    deque<char> dq;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') rev_cnt++;
        else {
            if (dq.empty()) dq.push_back(S[i]);
            else if (rev_cnt % 2 == 0) {
                if (!dq.empty() && dq.back() != S[i]) dq.push_back(S[i]);
                else dq.pop_back();
            }
            else {
                if (!dq.empty() && dq.front() != S[i]) dq.push_front(S[i]);
                else dq.pop_front();
            }
        }
    }

    string ans = "";
    while (!dq.empty()) {
        ans += dq.front();
        dq.pop_front();
    }
    if (ans.size() > 0 && rev_cnt % 2 != 0) reverse(ans.begin(), ans.end());
    cout << ans << endl;
}