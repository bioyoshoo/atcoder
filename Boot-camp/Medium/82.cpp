#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> V(N);
    double mean = 0;
    for (int i = 0; i < N; i++) {
        cin >> V.at(i);
        mean += V.at(i);
    }
    mean /= (double)N;
    mean = round(mean);
    
    int64_t ans = 0;
    for (int i = 0; i < N; i++) ans += pow(V.at(i) - mean, 2);

    cout << ans << endl;
}
