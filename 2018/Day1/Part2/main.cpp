#include <iostream>
#include <fstream>
#include <vector>
#include <set>

int main(int argc, char *argv[]) {
    if (argc != 2){
        std::cout << "Incorrect argument count" << std::endl;
        return 1;
    }

    std::vector<long> inputValues;

    std::ifstream inputFile(argv[1]);
    long tmp;
    while(!inputFile.eof()){
        inputFile >> tmp;
        inputValues.emplace_back(tmp);
    }
    inputFile.close();
    inputValues.erase(inputValues.end()-1);

    std::set<long> frequencies;
    long currentFreq = inputValues[0];
    const size_t ringbuff = inputValues.size();

    for(size_t i = 1;frequencies.insert(currentFreq).second; i++){
        tmp = i % ringbuff;
        currentFreq += inputValues[tmp];
    }

    std::cout << "Solution: " << currentFreq << std::endl;

    return 0;
}