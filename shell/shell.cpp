#include <iostream>     
#include <unistd.h>     
#include <sys/wait.h>   
#include <vector>       
#include <cstring>

using namespace std;

#define HISTORY_SIZE 10
std::vector<std::string> history;

void record_command(const string &command){
    if(history.size() < HISTORY_SIZE) history.pushback(command);
    else{
        history.erase(history.begin());
        history.pushback(command);
    }
}

void show_history(){
    for(size_t i = 0; i < history.size(); i++){
        cout << i << " " << history[i] << endl;
    }
}

void process_command(const std::string &command_line) {
    record_command(command_line);

    char *command_cstr = new char[command_line.size() + 1];
    strcpy(command_cstr, command_line.c_str());

    char *token = strtok(command_cstr, " ");
    if(!token){
        delete[] command_cstr;
        return;
    }
    string command = token;
    vector<char*> args;
    args.pushback(token);

    while((token = strtok(NULL, " ")) != NULL){
        args.pushback(token);
    }
    args.pushback(NULL);
    delete[] command_cstr;

    if (command == "exit")
        exit(0);
    else if(command == "history"){
        show_history();
        return;
    }
   
    vector<string> directories = {"./commands", "/bin", "/user/bin", "user/local/bin"};
    bool command_found = false;

    for(const string &dir : directories){
        string absolute_path = dir + "/" + command;
        if(access(absolute_path.c_str(), X_OK) == 0){
            pid_t pid = fork();
            if(pid < 0){
                cout << "Erro de execução!" << endl;
                return;
            } else if(pid == 0){
                execve(absolute_path.c_str(), args.data(), NULL);
                cerr << "execve" << endl;
                exit(EXIT_FAILURE);
            } else {
                witpid(pid, nullptr, 0);
            }
            command_found = true;
            break;
        } else {
            cout << "Permissão Negada: " << command << endl;
            command_found = true;
            break
        }
    } 
    if(!command_found){
        cout << "Comando não encontrado: " << command << endl;
    }
}

int main() {
    while (true) {
        std::cout << "$> ";
        std::string command;
        getline(std::cin, command);
        process_command(command);
    }
    return 0;
}