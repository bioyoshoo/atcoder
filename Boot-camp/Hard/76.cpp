#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t S;
    cin >> S;
    int N = to_string(S).size();

    int64_t ans = 0;
    for (int64_t i = 0; i < (1 << (N - 1)); i++) {
        vector<int> delim;
        int64_t s = S;
        for (int j = N - 1; j >= 0; j--) {
            if (i & 1 << j) delim.push_back(j);
        }

        int64_t sum = 0;
        if (delim.size() == 0) sum += S;
        else {
            for (int d: delim) {
                sum += s / (int)pow(10, d + 1);
                s %= (int)pow(10, d + 1);
            }
            sum += s;
        }
        
        ans += sum;
    }
    
    cout << ans << endl;
}