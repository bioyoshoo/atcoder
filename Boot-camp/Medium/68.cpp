#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for (int i = 0; i < H; i++) cin >> A.at(i);

    bool ans = true;
    for (int i = 1; i < H; i++) {
        for (int j = 1; j < W; j++) {
            if (A.at(i).at(j) == '#' && A.at(i - 1).at(j) == '#' && A.at(i).at(j - 1) == '#') {
                ans = false;
                goto OUT;
            } 
        }
    }
OUT:
    if (ans) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}