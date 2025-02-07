#include <iostream>
#include <vector>
using namespace std;

int main() {
    int S, N;
    cin >> S >> N;
    
    vector<int> dp(S + 1, 0);

    for (int i = 0; i < N; i++) {
        int size, value;
        cin >> size >> value;

        // Update DP array from right to left to prevent reuse of the same item
        for (int j = S; j >= size; j--) {
            dp[j] = max(dp[j], dp[j - size] + value);
        }
    }

    cout << dp[S] << endl;
    return 0;
}
