#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string linha;
    vector<int> number_vetor;
    int num_tests, num_sort, swaps;

    cin >> num_tests;

    while (num_tests > 0) {
        swaps = 0;
        number_vetor.clear();

        cin >> num_sort;
        cin.ignore();

        getline(cin, linha);
        stringstream ss(linha);
        int numero;
        while (ss >> numero) {
            number_vetor.push_back(numero);
        }

        // Insertion Sort
        for (int n = 1; n < num_sort; n++) {
            int saved_number = number_vetor[n];
            int j = n - 1;

            while (j >= 0 && number_vetor[j] > saved_number) {
                number_vetor[j + 1] = number_vetor[j];
                j--;
                swaps++;
            }
            number_vetor[j + 1] = saved_number;
        }

        // Output the results
        //cout << "O número de swaps foi de: " << swaps << endl;
        /*for (int j = 0; j < num_sort; j++) {
            cout << number_vetor[j] << " ";
        }*/
        cout<<swaps<<endl;
        //cout << endl;

        num_tests--;
    }

    return 0;
}
//Problema com o tempo;