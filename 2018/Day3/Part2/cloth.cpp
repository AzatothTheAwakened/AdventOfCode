#include "cloth.hpp"

#include <ios>
#include <sstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string.h>

#define MIN(a, b) (a < b) ? a : b
#define MAX(a, b) (a > b) ? a : b

Cloth::Cloth(int id, int posx, int posy, int width, int height) :
    m_id(id),
    m_posx(posx),
    m_posy(posy),
    m_width(width),
    m_heigth(height),
    m_grid(posx + width, std::vector<bool>(posy + height, false))
    { }

    

Cloth::Cloth(const std::string &input){

    sscanf(input.c_str(), "#%d @ %ld,%ld: %ldx%ld", 
        &m_id, 
        &m_posx, 
        &m_posy, 
        &m_width, 
        &m_heigth
    );
}


bool Cloth::operator()(size_t n, size_t k) const{
    if(n >= getBeginX() && n < getEndX()){
        if(k >= getBeginY() && k < getEndY()){
            return true;
        }
    }
    return false;
}


long Cloth::overlapping(const std::vector<Cloth> &source){

    int w = 0;
    int h = 0;
    int tmp;

    for(Cloth c : source){
        tmp = c.getEndX();
        w = MAX(w, tmp);
        tmp = c.getEndY();
        h = MAX(h, tmp);
    }

    std::cout << "Max size: " << w << "x" << h << std::endl; 

    std::vector<std::vector<int>> globGrid(w, std::vector<int>(h, 0));


    for(Cloth c : source){
        std::cout << "Drawing: " << "#" << c.getId() << std::endl;
        for(size_t i = c.getBeginX(); i < c.getEndX(); i++){
            for(size_t j = c.getBeginY(); j < c.getEndY() ; j++){
                if(c(i,j)){
                    globGrid[i][j]++;
                }
            }
        }
    }

    int count = 0;

    for(size_t i = 0; i < w; i++){
        for(size_t j = 0; j < h; j++){
            count += (globGrid[i][j] > 1) ? 1 : 0; 
        }
    }
    
    return count;
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