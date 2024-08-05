
#include <iostream>
#include <filesystem>
#include <sys/stat.h>

using namespace std;

int main(int argc, char *argv[]){
    if(argc != 3){
        cerr << "Uso: " << argv[0] << " <modo_de_permissao> <nome_do_arquivo>" << endl;
        return 0;
    }

    const char *modoPermissao = argv[1];
    const char *nomeDoArquivo = argv[2];

    int modo = strtol(modoPermissao, nullptr, 8);

    if(chmod(nomeDoArquivo, modo) == 0){
        cout << "Permissoes do arquivo '" << nomeDoArquivo << "' alteradas com sucesso." << endl;
        return 0;
    }
    else {
        cerr << "Erro ao alterar as permissões do arquivo" << endl;
        return 1;
    }
}
