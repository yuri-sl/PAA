#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void merge(vector<int>& arr, int left, int middle, int right) {
    int a1 = middle - left + 1;
    int a2 = right - middle;

    vector<int> L(a1), R(a2);

    for (int i = 0; i < a1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < a2; i++) {
        R[i] = arr[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < a1 && j < a2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < a1) {
        arr[k++] = L[i++];
    }

    while (j < a2) {
        arr[k++] = R[j++];
    }
}

// MergeSort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int main() {
    string inp;
    getline(cin, inp);

    vector<int> result;
    stringstream ss(inp);
    int num;

    // Extract integers from the input string
    while (ss >> num) {
        result.push_back(num);
    }

    if (!result.empty()) {
        mergeSort(result, 0, result.size() - 1);
    }

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
