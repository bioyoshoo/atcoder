#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t X;
    cin >> X;

    double min_a = (-1 + sqrt(1 + 8 * X)) / 2;

    cout << ceil(min_a) << endl;
}