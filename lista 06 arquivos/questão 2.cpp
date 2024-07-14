#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "mochileiro.txt";
    std::ifstream inputFile(filename);

    // Verifica se o arquivo foi aberto corretamente
    if (!inputFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << filename << std::endl;
        return 1;
    }

    char targetChar;
    std::cout << "Digite o caractere que deseja contar: ";
    std::cin >> targetChar;

    std::string line;
    int lineNumber = 0;

    // Lê cada linha do arquivo
    while (std::getline(inputFile, line)) {
        int count = 0;

        // Conta as ocorrências do caractere na linha atual
        for (char c : line) {
            if (c == targetChar) {
                count++;
            }
        }

        lineNumber++;
        std::cout << "Linha " << lineNumber << ": " << count << " ocorrência(s) de '" << targetChar << "'" << std::endl;
    }

    inputFile.close();
    return 0;
}

