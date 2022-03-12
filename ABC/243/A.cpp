#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, A, B, C;
    cin >> V >> A >> B >> C;

    int sum = A + B + C, res;
    res = V % sum;

    if (res < A) cout << "F" << endl;
    else if (res < A + B) cout << "M" << endl;
    else cout << "T" << endl;
}

