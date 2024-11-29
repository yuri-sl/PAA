#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int binarySearch(const vector<int>& number_vector, int x) {
    int left = 0, right = number_vector.size() - 1;
    int result = -1;  // Store the index of the first occurrence

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (number_vector[mid] == x) {
            result = mid;  // Update result to current index
            right = mid - 1;  // Continue searching on the left for the first occurrence
        } else if (x < number_vector[mid]) {
            right = mid - 1;  // Eliminate the right half
        } else {
            left = mid + 1;  // Eliminate the left half
        }
    }

    return result;  // Return the index of the first occurrence, or -1 if not found
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);  // Read values of n and q
    int x;

    string linha;
    vector<int> number_vector;

    cin.ignore();  // Ignore the newline after reading n and q
    getline(cin, linha);  // Read the line with numbers
    stringstream ss(linha);
    int numero;
    while (ss >> numero) {
        number_vector.push_back(numero);  // Fill the vector with numbers
    }

    // For each query, perform binary search
    for (int i = 0; i < q; i++) {
        scanf("%d", &x);  // Read the value of x for each query
        int result = binarySearch(number_vector, x);  // Perform binary search

        printf("%d", result);  // Print the found index or -1, followed by a newline
        printf("\n");
    }

    return 0;
}
