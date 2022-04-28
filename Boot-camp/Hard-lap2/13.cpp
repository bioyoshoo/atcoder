#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    int64_t ans = 0;
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            for (int c = 0; c < 10; c++) {
                vector<int> abc = {a, b, c};
                int cur = 0;
                for (int i = 0; i < N; i++) if (S[i] - '0' == abc[cur]) cur++;
                if (cur >= 3) ans++;
            }
        }
    }

    cout << ans << endl;
}