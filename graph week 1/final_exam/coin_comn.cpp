#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int coins[N];
int dp[N];

int main()
{
    int n, target;
    cin >> n >> target;

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp[0] = 1;  

    for (int j = 1; j <= target; j++) {
        for (int i = 0; i < n; i++) {
            if (coins[i] <= j) {
                dp[j] += dp[j - coins[i]];
            }
        }
    }

    cout << dp[target] << endl;

    return 0;
}
