#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t K, A, B;
    cin >> K >> A >> B;
    
    int64_t ans;
    if (K <= A || B - A < 2) ans = K + 1;
    else  {
        // Aまで持ってくる
        ans = A;
        K -= A - 1;
        while (K > 1) {
            ans += B - A;
            K -= 2;
        }
        if (K == 1) ans++;
    }
    
    cout << ans << endl;
}