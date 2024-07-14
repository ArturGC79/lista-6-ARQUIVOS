#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <limits>

int main() {
    std::string alturaFilename = "altura.txt";
    std::string pesoFilename = "peso.txt";

    std::ifstream alturaFile(alturaFilename);
    std::ifstream pesoFile(pesoFilename);

    if (!alturaFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << alturaFilename << std::endl;
        return 1;
    }

    if (!pesoFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << pesoFilename << std::endl;
        return 1;
    }

    std::map<std::string, double> alturaMap;
    std::map<std::string, double> pesoMap;

    std::string codigo;
    double medida;

    // Ler o arquivo de altura
    while (alturaFile >> codigo >> medida) {
        alturaMap[codigo] = medida;
    }

    // Ler o arquivo de peso
    while (pesoFile >> codigo >> medida) {
        pesoMap[codigo] = medida;
    }

    alturaFile.close();
    pesoFile.close();

    // Encontrar a pessoa com a maior altura
    std::string codigoMaiorAltura;
    double maiorAltura = -std::numeric_limits<double>::infinity();

    for (const auto& entry : alturaMap) {
        if (entry.second > maiorAltura) {
            maiorAltura = entry.second;
            codigoMaiorAltura = entry.first;
        }
    }

    // Encontrar a pessoa com o maior peso
    std::string codigoMaiorPeso;
    double maiorPeso = -std::numeric_limits<double>::infinity();

    for (const auto& entry : pesoMap) {
        if (entry.second > maiorPeso) {
            maiorPeso = entry.second;
            codigoMaiorPeso = entry.first;
        }
    }

    // Imprimir os resultados
    std::cout << "Pessoa com a maior altura: " << codigoMaiorAltura << " com " << maiorAltura << " metros" << std::endl;
    std::cout << "Pessoa com o maior peso: " << codigoMaiorPeso << " com " << maiorPeso << " kg" << std::endl;

    return 0;
}

