#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

int main() {
    int64_t A, B, C, D;
    cin >> A >> B >> C >> D;

    int64_t C_num, D_num, CD_num;
    C_num = B / C - (A - 1) / C;
    D_num = B / D - (A - 1) / D;
    CD_num = B / lcm(C, D) - (A - 1) / lcm(C, D);

    cout << B - A + 1 - C_num - D_num + CD_num << endl;
}

