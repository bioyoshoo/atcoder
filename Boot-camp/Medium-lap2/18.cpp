#include <bits/stdc++.h>
using namespace std;

bool check(int n, int div) {
    if (n % div != 0) return false;
    if (n / div < 0 || n / div > 100) return false;
    return true;
}

int main() {
    vector<vector<int>> table(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int c;
            cin >> c;
            table.at(i).at(j) = c;
        }
    }

    vector<int> Row;
    for (int i = 0; i < 3; i++) {
        int row_sum = 0;
        for (int j = 0; j < 3; j++) {
            row_sum += table.at(i).at(j);
        }
        Row.push_back(row_sum);
    }

    bool flag1 = false;
    for (int b1 = 0; b1 <= 100; b1++) {
        for (int b2 = 0; b2 <= 100; b2++) {
            for (int b3 = 0; b3 <= 100; b3++) {
                int sum_b = b1 + b2 + b3;

                bool flag2 = true;
                for (int i = 0; i < 3; i++) {
                    if (!check(Row[i] - sum_b, 3)) flag2 = false;
                }
                if (flag2) {
                    flag1 = true;
                    goto OUT;
                }
            }
        }
    }
OUT:
    if (flag1) cout << "Yes" << endl;
    else cout << "No" << endl;
}