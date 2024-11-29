#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int binarySearch(const vector<int>& number_vector, int x) {
    int left = 0, right = number_vector.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (number_vector[mid] == x) {
            return mid;  // Elemento encontrado, retorna o índice
        } else if (x < number_vector[mid]) {
            right = mid - 1;  // Elimina a metade direita
        } else {
            left = mid + 1;  // Elimina a metade esquerda
        }
    }

    return -1;  // Elemento não encontrado
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);  // Lê os valores de n e q
    int x;

    string linha;
    vector<int> number_vector;

    cin.ignore();  // Ignora a nova linha após a leitura de n e q
    getline(cin, linha);  // Lê a linha com os números
    stringstream ss(linha);
    int numero;
    while (ss >> numero) {
        number_vector.push_back(numero);  // Preenche o vetor com os números
    }

    // Para cada consulta, realiza a busca binária
    for (int i = 0; i < q; i++) {
        scanf("%d", &x);  // Lê o valor de x para cada consulta
        int result = binarySearch(number_vector, x);  // Realiza a busca binária

        printf("%d", result);  // Imprime o índice encontrado ou -1, seguido de uma nova linha
        printf("\n");
    }
        printf("\n");

    return 0;
}
