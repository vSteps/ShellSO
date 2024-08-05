#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        cerr << "Uso: " << argv[0] << " <nome_do_arquivo>" << endl;
        return 1;
    }
    const char *filename = argv[1];
    if(remove(filename) == 0){
        cout << "Arquivo ' " << filename << " ' removido com sucesso." << endl;
        return 0;
    }
    else{
        cerr << "Erro ao remover arquivo" << endl;
        return 1;
    }
}