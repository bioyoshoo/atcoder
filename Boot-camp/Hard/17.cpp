#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int base = 0;
    vector<int> edges(3, 0);

    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        int size = (int)S.size();

        for (int i = 0; i < size - 1; i++) {
            if (S.at(i) == 'A' && S.at(i + 1) == 'B') base++;
        }
        
        if (S.at(0) == 'B' && S.at(size - 1) == 'A') edges.at(2)++;
        else if (S.at(0) == 'B') edges.at(0)++;
        else if (S.at(size - 1) == 'A') edges.at(1)++;
    }

    int64_t joint;
    if (edges.at(2) == 0) joint = min(edges.at(0), edges.at(1));
    else {
        joint = (edges.at(2) - 1);
        if (edges.at(0) != 0 || edges.at(1) != 0) joint += min(edges.at(0), edges.at(1)) + 1;
    }

    cout << base + joint << endl;
}