#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> P;
    for (int i = 0; i < N; i++) {
        int c, x;
        cin >> c >> x;

        if (c == 1) P.push_back(x);
        
        else {
            int k, ans;
            cin >> k;
            sort(P.begin(), P.end());
            
            if (c == 2) {
                auto ind = lower_bound(P.begin(), P.end(), x);
                for (int i = 0; i < k - 1; i++) {
                    ind--;
                    if (i < k - 2 && ind == P.begin()) {
                        ans = -1;
                        break;
                    }
                }
                if (ans != -1) ans = *ind;
            }
            
            else if (c == 3) {
                auto ind = upper_bound(P.begin(), P.end(), x);
                for (int i = 0; i < k - 1; i++) {
                    ind++;
                    if (i != k - 2 && ind == P.begin()) {
                        ans = -1;
                        break;
                    }
                }
                if (ans != -1) ans = *ind;
            }

            cout << ans << endl;
        }
    }
}