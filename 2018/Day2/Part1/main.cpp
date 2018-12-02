#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>

std::vector<std::string> readInput(const char * const file);






int main(int argc, char *argv[]){

    if(argc != 2){
        std::cout << "Incorrect argument count" << std::endl;
        return 1;
    }

    std::vector<std::string> values = readInput(argv[1]);
    int trice = 0;
    int twice = 0;

    std::for_each(values.begin(), values.end(), [&twice, &trice](std::string x)-> void {
        std::map<char, int> counter;
        for(int i = 0; i < x.size(); i++){
            if(counter.find(x[i]) == counter.end()){
                counter[x[i]] = 1;
            } else {
                counter[x[i]]++;
            }
        }
        char hastwice = false;
        char hastrice = false;
        for(auto i = counter.begin(); i != counter.end(); i++){
            if(hastrice && hastwice){
                break;
            }
            switch(counter[i->first]){
                case 2:
                    hastwice = 1;
                    break;
                case 3:
                    hastrice = 1;
                    break;
            }
        }

        twice += hastwice;
        trice += hastrice;
    });

    std::cout << "Result: " << trice * twice << std::endl;
    return 0;

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