#include<bits/stdc++.h>
using namespace std;

bool is_palindrom(string s) {
    vector<int> character(26, 0);

    for (char c : s) {
        character[c - 'a']++;
    }

    int odd_count = 0;

    for (int count : character) {
        if (count % 2 != 0) {
            odd_count++;
        }
    }

    if (odd_count > 1) {
        return false;
    }

    return true;
}

int main() {
    string s;
    cin >> s;

    if (is_palindrom(s)) {
        cout << "YES" ;
    } else {
        cout << "NO" ;
    }

    return 0;
}
