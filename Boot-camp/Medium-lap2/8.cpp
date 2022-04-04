#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    vector<int> colors(9, 0);
    vector<int> borders = {1, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 8; j++) {
            if (borders[j] <= A[i] && A[i] < borders[j + 1]) colors[j]++;
        }
        if (A[i] >= 3200) colors[8]++;
    }

    int fixed_color = 0;
    for (int i = 0; i < 8; i++) if (colors[i] > 0) fixed_color++;

    int ans_min, ans_max;
    if (fixed_color > 0) ans_min = fixed_color;
    else ans_min = 1;

    ans_max = fixed_color + colors[8];

    cout << ans_min << " " << ans_max << endl;
}