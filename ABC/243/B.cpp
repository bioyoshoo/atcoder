#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int i = 0; i < N; i++) cin >> B.at(i);

    int ans_1 = 0;
    for (int i = 0; i < N; i++) {
        if (A.at(i) == B.at(i)) ans_1++;
    }

    int ans_2 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A.at(i) == B.at(j)) ans_2++;
        }
    }
    ans_2 -= ans_1;

    cout << ans_1 << endl;
    cout << ans_2 << endl;
}