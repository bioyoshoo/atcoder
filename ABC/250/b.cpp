#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    int H = A * N, W = B * N;
    for (int i = 0; i < H; i++) {
        int s_color;
        if (i / A % 2 == 0) s_color = 0;
        else s_color = 1;
        for (int j = 0; j < W; j++) {
            int color;
            if (j / B % 2 == 0) color = s_color;
            else color = 1 - s_color;
            if (color == 0) cout << ".";
            else cout << "#";
            if (j == W - 1) cout << endl;
        }
    }
}