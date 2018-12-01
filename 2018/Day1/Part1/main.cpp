#include <iostream>
#include <fstream>
#include <vector>

#ifdef DEBUG
#   include <iostream>
#   define DBGPRNT(ARG) std::cout << "DEBUG: " << ARG << std::endl;
#else
#   define DBGPRNT(ARG) 
#endif

int main(int argc, char* argv[]){
    if (argc != 2){
        std::cout << "Incorrect argument count" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    long solution = 0;
    long tmp;
    while(!inputFile.eof()){
        inputFile >> tmp;
        DBGPRNT(tmp);
        solution += tmp;
    }
    solution -= tmp;
    inputFile.close();
    std::cout << "solution: " << solution << std::endl;

    return 0;
}