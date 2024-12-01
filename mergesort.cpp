#include <iostream>
#include <vector>
#include <sstream> // For stringstream

using namespace std;

// Merge function to combine two sorted halves into a sorted array
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// MergeSort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    string inp;
    //cout << "Enter space-separated integers: ";
    getline(cin, inp); // Read the entire line of input

    vector<int> result;
    stringstream ss(inp);
    int num;

    // Extract integers from the input string
    while (ss >> num) {
        result.push_back(num);
    }

    // Debug: Check the contents of the result vector before sorting
    //cout << "Input parsed as integers: ";
    //for (int x : result) {
    //    cout << x << " ";
    //}
    //cout << endl;

    // Sort the vector using MergeSort
    if (!result.empty()) {
        mergeSort(result, 0, result.size() - 1);
    }

    // Print the sorted result
    //cout << "Sorted result: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
