#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> table(N);
    int start = 0, end = N - 1;
    
    for (int i = 0; i < 20; i++) {
        int query;
        if (i == 0) query = start;
        else if (i == 1) query = end;
        else query = start + (end - start) / 2;
        cout << query << endl;

        string s;
        cin >> s;
        if (s == "Vacant") break;
        
        table[query] = s;
        if (i > 1) {
            if ((query - start) % 2 == 1 && table[start] == table[query]) end = query;
            else if ((query - start) % 2 == 0 && table[start] != table[query]) end = query;
            else start = query;
        } 
    }
}