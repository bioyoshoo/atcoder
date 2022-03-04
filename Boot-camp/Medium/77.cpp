#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int64_t time = 1, step_time = 1900 * M + 100 * (N - M), pre_exp = 0, now_exp = 1, diff = 1e10;
    double succes = pow(0.5, M);
    while (diff > 0) {
        now_exp = pre_exp + step_time * time * pow(1 - succes, time - 1) * succes;
        diff = now_exp - pre_exp;
        pre_exp = now_exp;
        time++;
    }

    cout << now_exp << endl;
}