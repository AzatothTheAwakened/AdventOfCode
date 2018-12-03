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

    vector<Cloth> cloths;
    readInput(argv[1], cloths);

    vector<vector<vector<int>>> grid;
    long overlappingCount = Cloth::overlapping(cloths, grid);

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    
    int nonOverlappingId = Cloth::nonOverlappingId(grid);

    high_resolution_clock::time_point t3 = high_resolution_clock::now();


    auto duration1 = duration_cast<milliseconds>(t2 - t1).count();
    auto duration2 = duration_cast<milliseconds>(t3 - t2).count();
    auto duration3 = duration_cast<milliseconds>(t3 - t1).count();
    cout << "Result Overlapping: " << overlappingCount << "\t Time: " << duration1 << endl;
    cout << "Result NonOverlapping: " << nonOverlappingId << "\t Time: " << duration2 << endl;
    cout << "Time combined: " << duration3 << endl;

    return 0;
}

