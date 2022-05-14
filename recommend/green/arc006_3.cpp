#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> floor;
    for (int i = 0; i < N; i++) {
        int w; cin >> w;
        if (i == 0) floor.push_back(w);
        else {
            int n = floor.size();
            bool insert = false;
            for (int j = 0; j < n; j++) {
                if (w <= floor[j]) {
                    floor[j] = w;
                    insert = true;
                    break;
                }
            }
            if (!insert) floor.push_back(w);
        }
    }
    cout << floor.size() << endl;
}