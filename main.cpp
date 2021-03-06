#include <vector>
#include <map>
#include "DefineVarCommand.h"
//#include "DefineVarCommand.cpp"
#include "WhileCommand.h"
//#include "WhileCommand.cpp"
#include "ex1.h"
#include "OpenDataServerCommand.h"
//#include "OpenDataServerCommand.cpp"
#include "ConnectControlClientCommand.h"
//#include "ConnectControlClientCommand.cpp"
#include "PrintCommand.h"
//#include "PrintCommand.cpp"
#include "SleepCommand.h"
//#include "SleepCommand.cpp"
#include "IfCommand.h"
#include "globals.h"
//#include "IfCommand.cpp"
//#include "globals.cpp"



using namespace std;

std::vector<std::string> split(const std::string &s, char c);

bool ignoreChars(char ch);

void MakeCommandMap();

void updateVarValue(string basicString, string basicString1);

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int main(int argc, char *argv[]) {
    string path = "fly.txt";
    if(argc > 0) {
        path = argv[1];
    }
    MakeCommandMap();
    std::string file_path(path); // I assumed you have that kind of file
    std::ifstream in_s(file_path);

    std::vector<std::string> content;
    ifstream file(path);

    string line;
    while (std::getline(file, line)) {
        content.push_back(line);
    }
    endOfFile = false;
    // at this point, content contains fly.txt line by line.
    int i = 0, contentSize = content.size();
    while (i < contentSize) {
        i = executeFromContent(content, i, CommandList) + 1;
    }
    endOfFile = true;
    threads[0].join();
    threads[1].join();

    return 0;
}

void MakeCommandMap() {
    CommandList["var"] = new DefineVarCommand();
    CommandList["while"] = new WhileCommand();
    CommandList["if"] = new IfCommand();
    CommandList["openDataServer"] = new OpenDataServerCommand();
    CommandList["connectControlClient"] = new ConnectControlClientCommand();
    CommandList["Print"] = new PrintCommand();
    CommandList["Sleep"] = new SleepCommand();
}