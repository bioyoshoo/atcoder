#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> plug(M, vector<int>(N, 0));
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int s;
            cin >> s;
            plug.at(i).at(s - 1) = 1;
        }
    }
    vector<int> P(M);
    for (int i = 0; i < M; i++) cin >> P.at(i);

    int64_t ans = 0;
    for (int pattern = 0; pattern < (1 << N); pattern++) {
        vector<int> Light(M, 0);
        for (int swt = 0; swt < N; swt++) {
            if (pattern & (1 << swt)) {
                for (int light = 0; light < M; light++) {
                    Light.at(light) += plug.at(light).at(swt);
                }
            }
        }
        bool flag = true;
        for (int i = 0; i < M; i++) {
            if (Light.at(i) % 2 != P.at(i)) flag = false;
        }

        if (flag) ans++;
    }

    cout << ans << endl;
}