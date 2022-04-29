#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t K;
    cin >> K;

    queue<int64_t> todo;
    for (int i = 1; i <= 9; i++) todo.push(i);
    vector<int> d = {-1, 0, 1};
    int64_t n;
    for (int k = 0; k < K; k++) {
        n = todo.front();
        todo.pop();

        int last_n = n % 10;
        for (int i = 0; i < 3; i++) {
            if (last_n == 0 && d[i] == -1) continue;
            else if (last_n == 9 && d[i] == 1) continue;
            int64_t new_n = 10 * n + (last_n + d[i]);
            todo.push(new_n);
        }
    }

    cout << n << endl;
}