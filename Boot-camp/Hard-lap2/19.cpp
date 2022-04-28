#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    vector<vector<int>> ans(H, vector<int>(W));
    
    int c = 0;
    for (int h = 0; h < H; h++) {
        if (h % 2 == 0) for (int w = 0; w < W; w++) {
            if (A[c] == 0) c++;
            ans[h][w] = c + 1;
            A[c]--;
        }
        else for (int w = W - 1; w >= 0; w--) {
            if (A[c] == 0) c++;
            ans[h][w] = c + 1;
            A[c]--;
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << ans[i][j] << " ";
            if (j == W - 1) cout << endl;
        }
    }
}