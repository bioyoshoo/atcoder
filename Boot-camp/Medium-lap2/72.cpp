#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int64_t ans;
    for (int i = 0; i < N; i++) {
        int64_t t;
        cin >> t;
        
        if (i == 0) ans = t;
        else ans = lcm(ans, t);
    }

    cout << ans << endl;
}