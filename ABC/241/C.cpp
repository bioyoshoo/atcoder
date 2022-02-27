#include <bits/stdc++.h>
using namespace std;

bool black_num(string S) {
    int cnt = 0;
    for (auto s: S) {
        if (s == '#') cnt++;
    }
    if (cnt >= 4) return true;
    else return false;
}

int main() {
    int N;
    cin >> N;
    vector<string> D(N);
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        D.at(i) = S;
    }
    
    bool ans = false;
    for (int i = 0; i < N - 5; i++) {
        for (int j = 0; j < N - 5; j++) {
            vector<string> Part(6);
            for (int k = 0; k < 6; k++) Part.at(k) = D.at(i + k).substr(j, 6);

            // row
            for (int r = 0; r < 6; r++) {
                string row = Part.at(r);
                if (black_num(row)) {
                    ans = true;
                    goto OUT;
                }
            }

            // col
            for (int c = 0; c < 6; c++) {
                string col;
                for (int r = 0; r < 6; r++) {
                    col += Part.at(r).at(c);

                    if (r == 5) {
                        if (black_num(col)) {
                            ans = true;
                            goto OUT;
                        }
                    }
                }
            }

            // lateral
            string rat_1, rat_2;
            for (int i = 0; i < 6; i++) {
                rat_1 += Part.at(i).at(i);
                rat_2 += Part.at(i).at(5 - i);
            }
            if (black_num(rat_1) || black_num(rat_2)) {
                ans = true;
                goto OUT;
            }
        } 
    }

OUT:
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}