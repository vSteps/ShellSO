#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
    if(argc < 2){
        cerr << "Uso: " << argv[0] << " <arquivo1 [<arquivo2> ...]" << endl;
        return 1;
    }
    for(int i = 1; i<argc; i++){
        ifstream file(argv[i]);
        if(!file.is_open()){
            cerr << "Erro ao abrir arquivo: " << argv[i] << endl;
            continue;
        }
        cout << "Conteúdo do arquivo '" << argv[i] << "':" << endl;
        char c;
        while(file.get(c)){
            cout << c;
        }
        file.close();
    }
    return 0;
}