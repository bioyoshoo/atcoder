#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    long double x = sqrt((long double)1 / (a * a + b * b));

    cout << fixed << setprecision(10);
    cout << a * x << " " << b * x << endl;
}