#include "cloth.hpp"
#include <iostream>
#include <fstream>
#include <chrono>


void readInput(const char * const file, std::vector<Cloth> &target);

void readInput(const char * const file, std::vector<Cloth> &target){
    std::vector<Cloth> values;
    std::ifstream inputFile(file);

    
    for(std::string line; std::getline(inputFile, line);){
        values.emplace_back(line);
    }
    inputFile.close();

    target = std::move(values);
}





using namespace std::chrono;
using namespace std;

int main(int argc, char *argv[]){
    if(argc != 2){
        cout << "Incorrect argument count" << endl;
        return 1;
    }
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    std::vector<Cloth> cloths;
    readInput(argv[1], cloths);
    long overlappingCount = Cloth::overlapping(cloths);

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(t2 - t1).count();


    std::cout << "Result: " << overlappingCount << "\t Time: " << duration << std::endl;

    // Cloth c(string("#1 @ 1,3: 4x4"));

    // cout << c.getBeginX() << "-" << c.getEndX() << endl;
    // cout << c.getBeginY() << "-" << c.getEndY() << endl;

    return 0;
}

