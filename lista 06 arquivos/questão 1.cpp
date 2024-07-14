#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::ifstream inputFile("vetores.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo vetores.txt" << std::endl;
        return 1;
    }

    std::vector<int> sumVector;
    std::string line;

    // Ler cada linha do arquivo
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        int value;
        std::vector<int> currentVector;

        // Ler cada valor na linha e adicioná-lo ao vetor atual
        while (ss >> value) {
            currentVector.push_back(value);
        }

        // Ajustar o tamanho do vetor de soma se necessário
        if (sumVector.size() < currentVector.size()) {
            sumVector.resize(currentVector.size(), 0);
        }

        // Somar os valores ao vetor de soma
        for (size_t i = 0; i < currentVector.size(); ++i) {
            sumVector[i] += currentVector[i];
        }
    }

    inputFile.close();

    std::ofstream outputFile("soma.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo soma.txt" << std::endl;
        return 1;
    }

    // Escrever o vetor de soma no arquivo de saída
    for (size_t i = 0; i < sumVector.size(); ++i) {
        outputFile << sumVector[i];
        if (i != sumVector.size() - 1) {
            outputFile << " ";
        }
    }

    outputFile.close();
    std::cout << "A soma dos vetores foi salva no arquivo soma.txt" << std::endl;

    return 0;
}

