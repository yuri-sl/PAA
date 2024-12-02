#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int binSearch(const vector<int>& number_vector, int x) {
    int left = 0, right = number_vector.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (number_vector[mid] == x) {
            result = mid; 
            right = mid - 1; 
        } else if (x < number_vector[mid]) {        //Eliminar metade direita
            right = mid - 1;
        } else {
            left = mid + 1;     // Eliminar a metade esquerda half
        }
    }

    return result; 
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q); 
    int x;

    string linha;
    vector<int> number_vector;

    cin.ignore(); 
    getline(cin, linha); 
    stringstream ss(linha);
    int numero;
    while (ss >> numero) {
        number_vector.push_back(numero);
    }

    for (int i = 0; i < q; i++) {
        scanf("%d", &x); 
        int result = binSearch(number_vector, x);  
        
        printf("%d", result);  
        printf("\n");
    }

    return 0;
}
