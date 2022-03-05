#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    double ans;
    if (X <= A) {
        ans = 1;
    }
    else if (A < X && X <= B) {
        ans = (double)C / (double)(B - A);
    }
    else if (X > B) {
        ans = 0;
    }

    cout << fixed << setprecision(10);
    cout << ans << endl;
}