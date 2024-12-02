#include <iostream>
#include <vector>

using namespace std;

// Function to perform insertion sort and count the number of swaps
int countSwaps(vector<int>& arr) {
    int swapCount = 0;
    int N = arr.size();

    for (int i = 1; i < N; i++) {
        int j = i;
        while (j > 0 && (arr[j] < arr[j - 1])) {
            // Swap using XOR operation
            arr[j] ^= arr[j - 1];
            arr[j - 1] ^= arr[j];
            arr[j] ^= arr[j - 1];

            j--;
            swapCount++;
        }
    }

    return swapCount;
}

int main() {
    int T;
    scanf("%d", &T); // Read the number of test cases

    while (T--) {
        int N;
        scanf("%d", &N); // Read the size of the array

        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]); // Read the array elements
        }

        // Count swaps using insertion sort
        int swaps = countSwaps(arr);

        // Output the result for the current test case
        printf("%d\n", swaps);
    }

    return 0;
}
