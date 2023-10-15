#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int coins[n];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    set<int> sums;
    sums.insert(0);

    for (int i = 0; i < n; i++) {
        set<int> temp_sums;
        for (int sum : sums) {
        temp_sums.insert(sum + coins[i]);
        }

        sums.insert(temp_sums.begin(), temp_sums.end());

    }

    sums.erase(0); 

    cout << sums.size()<<"\n";

    for (int sum : sums) {
        cout << sum << " ";
    }

    return 0;
}
