#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>

int main() {
    char dir[10];

    std::cout << "Digite o nome do diretório a ser removido: ";
    std::cin >> dir;

    if (rmdir(dir) != 0) {
        std::cerr << "Erro ao remover o diretório " << dir << ": " << strerror(errno) << std::endl;
    } else {
        std::cout << "Diretório " << dir << " removido com sucesso." << std::endl;
    }

    return 0;
}