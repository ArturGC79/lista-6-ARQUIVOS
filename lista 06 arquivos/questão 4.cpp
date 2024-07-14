#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

void cadastrarAluno() {
    std::string nome;
    std::string matricula;
    
    std::cout << "Digite o nome do aluno: ";
    std::cin.ignore();
    std::getline(std::cin, nome);
    std::cout << "Digite a matrícula do aluno: ";
    std::getline(std::cin, matricula);
    
    std::ofstream alunoFile(nome + ".txt");
    if (alunoFile.is_open()) {
        alunoFile << matricula << std::endl;
        alunoFile.close();
        std::cout << "Aluno " << nome << " cadastrado com sucesso." << std::endl;
    } else {
        std::cerr << "Erro ao criar o arquivo para o aluno " << nome << std::endl;
    }
}

void adicionarNota() {
    std::string nome;
    double nota;
    
    std::cout << "Digite o nome do aluno: ";
    std::cin.ignore();
    std::getline(std::cin, nome);
    
    std::ifstream alunoFile(nome + ".txt");
    if (!alunoFile.is_open()) {
        std::cerr << "Aluno " << nome << " não cadastrado." << std::endl;
        return;
    }
    
    alunoFile.close();
    
    std::cout << "Digite a nota do aluno: ";
    std::cin >> nota;
    
    std::ofstream alunoFileOut(nome + ".txt", std::ios::app);
    if (alunoFileOut.is_open()) {
        alunoFileOut << nota << std::endl;
        alunoFileOut.close();
        std::cout << "Nota adicionada com sucesso para o aluno " << nome << std::endl;
    } else {
        std::cerr << "Erro ao abrir o arquivo para o aluno " << nome << std::endl;
    }
}

void calcularMedia() {
    std::string nome;
    std::cout << "Digite o nome do aluno: ";
    std::cin.ignore();
    std::getline(std::cin, nome);
    
    std::ifstream alunoFile(nome + ".txt");
    if (!alunoFile.is_open()) {
        std::cerr << "Aluno " << nome << " não cadastrado." << std::endl;
        return;
    }
    
    std::string linha;
    std::getline(alunoFile, linha); // Ignora a primeira linha (matrícula)
    
    std::vector<double> notas;
    while (std::getline(alunoFile, linha)) {
        std::stringstream ss(linha);
        double nota;
        ss >> nota;
        notas.push_back(nota);
    }
    
    alunoFile.close();
    
    if (notas.empty()) {
        std::cout << "Nenhuma nota encontrada para o aluno " << nome << std::endl;
        return;
    }
    
    double soma = 0.0;
    for (double nota : notas) {
        soma += nota;
    }
    
    double media = soma / notas.size();
    std::cout << "A média do aluno " << nome << " é " << media << std::endl;
}

int main() {
    int opcao;
    
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Cadastrar aluno\n";
        std::cout << "2. Adicionar nota de um aluno\n";
        std::cout << "3. Calcular média de um aluno\n";
        std::cout << "4. Fechar o programa\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        
        switch (opcao) {
            case 1:
                cadastrarAluno();
                break;
            case 2:
                adicionarNota();
                break;
            case 3:
                calcularMedia();
                break;
            case 4:
                std::cout << "Fechando o programa..." << std::endl;
                break;
            default:
                std::cerr << "Opção inválida. Tente novamente." << std::endl;
        }
    } while (opcao != 4);
    
    return 0;
}

