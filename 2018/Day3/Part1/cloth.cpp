#include "cloth.hpp"

#include <ios>
#include <sstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string.h>
#include <utility>

#define MIN(a, b) (a < b) ? a : b
#define MAX(a, b) (a > b) ? a : b

using namespace std;

set<int> Cloth::s_knownIds = set<int>();

Cloth::Cloth(int id, int posx, int posy, int width, int height) :
    m_id(id),
    m_posx(posx),
    m_posy(posy),
    m_width(width),
    m_heigth(height),
    m_grid(posx + width, std::vector<bool>(posy + height, false))
    { 
        s_knownIds.insert(m_id);
    }

    

Cloth::Cloth(const std::string &input){

    sscanf(input.c_str(), "#%d @ %ld,%ld: %ldx%ld", 
        &m_id, 
        &m_posx, 
        &m_posy, 
        &m_width, 
        &m_heigth
    );

    s_knownIds.insert(m_id);
}


bool Cloth::operator()(size_t n, size_t k) const{
    if(n >= getBeginX() && n < getEndX()){
        if(k >= getBeginY() && k < getEndY()){
            return true;
        }
    }
    return false;
}



long Cloth::overlapping(const vector<Cloth> &source, vector<vector<vector<int>>> &dest){

    int w = 0;
    int h = 0;
    int tmp;

    for(Cloth c : source){
        tmp = c.getEndX();
        w = MAX(w, tmp);
        tmp = c.getEndY();
        h = MAX(h, tmp);
    }

    cout << "Max size: " << w << "x" << h << endl; 

    dest = vector<vector<vector<int>>>(w, vector<vector<int>>(h, vector<int>()));


    for(Cloth c : source){
        cout << "Drawing: " << "#" << c.getId() << endl;
        for(size_t i = c.getBeginX(); i < c.getEndX(); i++){
            for(size_t j = c.getBeginY(); j < c.getEndY() ; j++){
                if(c(i,j)){
                    dest[i][j].emplace_back(c.getId());
                }
            }
        }
    }

    int count = 0;

    for(size_t i = 0; i < w; i++){
        for(size_t j = 0; j < h; j++){
            count += (dest[i][j].size() > 1) ? 1 : 0; 
        }
    }
    
    return count;
}

int Cloth::nonOverlappingId(const std::vector<std::vector<std::vector<int>>> &grid){
    set<int> tmpIds = getKnownIds();

    for(size_t i = 0; i < grid.size(); i++){
        for(size_t j = 0; j < grid[i].size(); j++){
            if(grid[i][j].size() > 1){
                for(int id : grid[i][j]){
                    tmpIds.erase(id);
                }
            }
        }
    }

    return *tmpIds.begin();
}





const std::set<int> &Cloth::getKnownIds(){
    return s_knownIds;
}





int &Cloth::getHeighth(){
    return m_heigth;
}

int &Cloth::getId(){
    return m_id;
}

int &Cloth::getPosX(){
    return m_posx;
}

int &Cloth::getPosY(){
    return m_posy;
}

int &Cloth::getWidth(){
    return m_width;
}



const int &Cloth::getHeighth() const{
    return m_heigth;
}

const int &Cloth::getId() const{
    return m_id;
}

const int &Cloth::getPosX() const{
    return m_posx; 
}

const int &Cloth::getPosY() const{
    return m_posy;
}

const int &Cloth::getWidth() const{
    return m_width;
}

const std::vector<std::vector<bool>> &Cloth::getGrid() const{
    return m_grid;
}



int Cloth::getBeginX() const{
    return m_posx;
}

int Cloth::getEndX() const{
    return getBeginX() + m_width;
}

int Cloth::getBeginY() const{
    return m_posy;
}

int Cloth::getEndY() const{
    return getBeginY() + m_heigth;
}