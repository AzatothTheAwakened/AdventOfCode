#include <vector>
#include <string>
#include <fstream>
#include <iostream>

std::vector<std::string> readInput(const char * const file);
const std::string* const compare(const std::string &a, const std::string &b);




int main(int argc, char *argv[]){

    if(argc != 2){
        std::cout << "Incorrect argument count" << std::endl;
        return 1;
    }

    std::vector<std::string> values = readInput(argv[1]);
    const std::string* solution;

    for(size_t i = 0; i < values.size(); i++){
        for(size_t j = i+1; j < values.size(); j++){
            if(j == i){
                continue;
            }
            solution = compare(values[i], values[j]);
            if(solution != nullptr){
                break;
            }
        }
        if(solution != nullptr){
            break;
        }
    }

    std::cout << "Solution: " << *solution << std::endl;
    delete solution;
    return 0;
}


const std::string* const compare(const std::string &a, const std::string &b){
    std::string* samecharacters = new std::string;
    int counter = 0;

    for(size_t i = 0; i < a.size(); i++){
        if(a[i] == b[i]){
            *samecharacters += a[i];
        } else {
            counter++;
        }
        if(counter > 1){
            delete samecharacters;
            return nullptr;
        }
    }
    return samecharacters;
}

std::vector<std::string> readInput(const char * const file){
    std::vector<std::string> values;
    std::ifstream inputFile(file);

    
    for(std::string line; std::getline(inputFile, line);){
        values.emplace_back(line);
    }
    inputFile.close();

    return values;
}

