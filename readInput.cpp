#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string linha;
    vector<int> numeros;

    cout << "Digite uma linha de números separados por espaços: ";
    getline(cin, linha); // Lê a linha inteira como uma string

    stringstream ss(linha); // Cria um stream a partir da string
    int numero;

    // Extrai os números do stream e os adiciona ao vetor
    while (ss >> numero) {
        numeros.push_back(numero);
    }

    // Exibe os números armazenados no vetor
    cout << "Números armazenados no vetor: ";
    for (int n : numeros) {
        cout << n << " "<<endl;
    }
    cout<<numeros[0]<<endl;

    return 0;
}
