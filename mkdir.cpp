#include <iostream>
#include <sys/stat.h>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    if(argc != 2){
        cerr << "Uso: " << argv[0] << " <nome_do_arquivo>" << endl;
        return 1;
    }
    const char *nomeDoDiretorio = argv[1];

    if(mkdir(nomeDoDiretorio, 0777) == 0){
        cout << "Diretorio '" << nomeDoDiretorio << "' criado com sucesso." << endl;
        return 0;
    }
    else{
        cerr << "Erro ao criar diretorio" << endl;
        return 1;
    }
}