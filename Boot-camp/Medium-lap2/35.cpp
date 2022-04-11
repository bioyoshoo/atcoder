#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t A, B, C, D;
    cin >> A >> B >> C >> D;

    int64_t c_num = B / C - (A - 1) / C;
    int64_t d_num = B / D - (A - 1) / D;
    int64_t cd_num = B / lcm(C, D) - (A - 1) / lcm(C, D);
    cout << B - A + 1 - (c_num + d_num - cd_num) << endl;
}