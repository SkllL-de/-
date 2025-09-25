#include <iostream>
#include <algorithm>
using namespace std;

long long dp[1005];

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        // 从右向左计算
        for(int j = i; j >= 1; j--){
            int num;
            cin >> num;
            
            if(j == 1) {
                dp[j] += num;
            } else if(j == i) {
                dp[j] = dp[j-1] + num;
            } else {
                dp[j] = max(dp[j-1], dp[j]) + num;
            }
        }
    }
    
    cout << *max_element(dp + 1, dp + n + 1);
    return 0;
}