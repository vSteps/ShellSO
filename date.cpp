#include <time.h>
#include <iostream>

int main(){
    time_t t = time(NULL);
    std::cout << ctime(&t);
    return 0;
}