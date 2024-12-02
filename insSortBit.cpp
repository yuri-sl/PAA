#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_VAL = 1000000;

void update(vector<int>& bit, int index, int value) {
    while (index <= MAX_VAL) {
        bit[index] += value;
        index += index & -index;
    }
}

int query(const vector<int>& bit, int index) {
    int sum = 0;
    while (index > 0) {
        sum += bit[index];
        index -= index & -index;
    }
    return sum;
}

long long countSwaps(const vector<int>& arr) {
    vector<int> bit(MAX_VAL + 1, 0);
    long long swaps = 0;
    
    for (int i = arr.size() - 1; i >= 0; --i) {
        swaps += query(bit, arr[i] - 1);
        update(bit, arr[i], 1);
    }
    
    return swaps;
}

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        int N;
        scanf("%d",&N);
        vector<int> arr(N);
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }
        cout << countSwaps(arr) << endl;
    }
    return 0;
}
