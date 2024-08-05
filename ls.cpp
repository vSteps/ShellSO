#include <iostream>
#include <dirent.h>

int main(){
    char argc[10];
    DIR *p;
    struct dirent *d;
    scanf("%s", argc);
    p = opendir(argc);
    if(p == NULL){
        printf("DIRETÓRIO NÃO ENCONTRADO");
    }
    while(NULL != (d = readdir(p))){
        std::cout << std::endl << d->d_name;
    }
    std::cout << std::endl;
}