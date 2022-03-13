#include <bits/stdc++.h>
using namespace std;

int main() {
    int K;
    cin >> K;

    queue<int64_t> todo;
    for (int i = 1; i < 10; i++) todo.push(i);

    int64_t v;
    for (int i = 0; i < K; i++) {
        v = todo.front();
        todo.pop();
        int last_n = v % 10;
        int64_t next_v = 10 * v;
        
        if (last_n == 0) {
            todo.push(next_v);
            todo.push(next_v + 1);
        }
        else if (last_n == 9) {
            todo.push(next_v + 8);
            todo.push(next_v + 9);
        }
        else {
            todo.push(next_v + last_n - 1);
            todo.push(next_v + last_n);
            todo.push(next_v + last_n + 1);
        }
    }

    cout << v << endl;
}