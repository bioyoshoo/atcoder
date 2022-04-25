#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t A, B, C, D, E, F, X;
    cin >> A >> B >> C >> D >> E >> F >> X;

    int64_t a, b;
    a = (A * B) * (X / (A + C));
    if (X % (A + C) <= A) a += B * (X % (A + C));
    else a += A * B;

    b = (D * E) * (X / (D + F));
    if (X % (D + F) <= D) b += E * (X % (D + F));
    else b += D * E;

    if (a > b) cout << "Takahashi" << endl;
    else if (a < b) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
}