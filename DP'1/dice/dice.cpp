#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> dp(n+1, 0);

    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int dice = 1; dice <= 6; dice++){
            if(i - dice >= 0){
                dp[i] += dp[i-dice];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[n] << "\n";
    return 0;
}
