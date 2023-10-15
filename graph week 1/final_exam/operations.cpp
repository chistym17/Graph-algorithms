#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    string x_str = to_string(x);
    int length = x_str.length();

    if (length >= n) {
        cout << 0 << endl;
        return 0;
    }

    int operations = 0;
    unordered_set<char> digits;

    for (char ch : x_str) {
        digits.insert(ch);
    }

    while (length < n) {
        char chosen_digit = '0';

        for (char digit : digits) {
            if (digit != '0') {
                int new_length = length + log10(x) / log10(digit - '0') + 1;
                if (new_length <= n) {
                    chosen_digit = digit;
                    length = new_length;
                    break;
                }
            }
        }

        if (chosen_digit == '0') {
            cout << -1 << endl;
            return 0;
        }

        x *= (chosen_digit - '0');
        digits.insert(chosen_digit);
        operations++;
    }

    cout << operations << endl;

    return 0;
}
