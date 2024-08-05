#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[]){
    if(argc != 3){
        cerr << "Uso: " << argv[0] << " <origem> <destino>" << endl;
        return 1;
    }
    const char *origem = argv[1];
    const char *destino = argv[2];

    if(rename(origem, destino) != 0){
        cerr << "Erro ao mover arquivo" << endl;
        return 1;
    }
    else{
        cout << "Arquivo movido com sucesso de " << origem << " para " << destino << endl;
        return 0;
    }
}