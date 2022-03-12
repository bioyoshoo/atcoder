#include <bits/stdc++.h>
using namespace std;
const int64_t MAX = 20;

int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    int64_t up = MAX, bottom = 0;
    while (up - bottom > 2) {
        int64_t middle = bottom + (up - bottom) / 2;
        middle += (middle % 2) * 1;

        int64_t right_side = middle / 2;
        for (int i = 0; i <= N / 2; i++) right_side = A.at(i) - right_side;

        int64_t left_side = middle / 2;
        for (int i = N - 1; i > N / 2; i--) left_side = A.at(i) - left_side;

        if (right_side + left_side > A.at(N / 2)) up = middle;
        else bottom = middle;
    }

    cout << bottom << endl;
}