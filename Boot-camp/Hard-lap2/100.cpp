#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    string s;
    vector<int> V(N, -1);
    int left = 0, right = N - 1;
    int query;
    for (int i = 0; i < 20; i++) {
        if (i == 0) query = 0;
        else if (i == 1) query = N - 1;
        else query = (left + right) / 2;
        cout << query << endl;
        
        cin >> s;
        if (s == "Vacant") break;
        if (s == "Male") V[query] = 0;
        else V[query] = 1;

        if (i > 1) {
            int n = query - left + 1;
            if (n % 2 == 0) {
                if (V[left] == V[query]) right = query;
                else left = query;
            }
            else {
                if (V[left] == V[query]) left = query;
                else right = query;
            }
        }
    }
}