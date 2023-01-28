#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {

    while (true) {
        vector<int> T(60*60*24+1);

        int n; cin >> n;
        if (n == 0) break;

        int h, m, s;
        rep(i, n) {
            scanf("%d:%d:%d",&h,&m,&s);
            int start = 3600*h + 60*m + s;
            scanf("%d:%d:%d",&h,&m,&s);
            int end = 3600*h + 60*m + s;

            T[start] += 1; T[end] -= 1;
        }

        for (int x = 1; x <= 60*60*24; x++) T[x] += T[x - 1];

        int ans = -1;
        for (int x = 0; x <= 60*60*24; x++) {
            if (ans < T[x]) ans = T[x];
        }

        cout << ans << endl;
    }
}
