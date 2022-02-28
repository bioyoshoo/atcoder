#include <bits/stdc++.h>
using namespace std;

char ctoC(char c) {
    return c + 'A' - 'a';
}

int main() {
    string Sa, Sb, Sc;
    cin >> Sa >> Sb >> Sc;
    map<char, string> MS;
    MS['a'] = Sa;
    MS['b'] = Sb;
    MS['c'] = Sc;
   
    map<char, int> ML;
    ML['a'] = 0;
    ML['b'] = 0;
    ML['c'] = 0;
    
    char person = 'a';
    while (true) {
        ML.at(person)++;
        if (ML.at(person) == (int)MS.at(person).size()) break;
        
        person = MS.at(person).at(ML.at(person));
    }

    cout << ctoC(person) << endl;
}