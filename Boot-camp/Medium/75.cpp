#include <bits/stdc++.h>
using namespace std;

int64_t point(char c, int R, int S, int P) {
    if (c == 'r') return R;
    else if (c == 's') return S;
    else return P;
}

char win(char c) {
    if (c == 'r') return 'p';
    else if (c == 's') return 'r';
    else return 's';
}

int main() {
    int N, K, R, S, P;
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;

    set<char> choice;
    choice.insert('r');
    choice.insert('s');
    choice.insert('p');

    vector<set<char>> C(N, choice);

    int64_t ans = 0;
    for (int i = 0; i < N; i++) {
        char my_hand = win(T.at(i));
        set<char> my_choice = C.at(i);

        if (my_choice.count(my_hand)) {
            ans += point(my_hand, R, S, P);
            if (i + K < N) C.at(i + K).erase(my_hand);
        }
    }

    cout << ans << endl;
}