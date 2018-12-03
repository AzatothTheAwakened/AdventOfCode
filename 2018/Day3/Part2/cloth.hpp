#include <string>
#include <vector>


class Cloth{

private:
    int m_id;
    int m_posx;
    int m_posy;
    int m_width;
    int m_heigth;

    std::vector<std::vector<bool>> m_grid;


public:
    Cloth(int id, int posx, int posy, int width, int height);
    Cloth(const std::string &input);

    int &getId();
    int &getPosX();
    int &getPosY();
    int &getWidth();
    int &getHeighth();


    const int &getId() const;
    const int &getPosX() const;
    const int &getPosY() const;
    const int &getWidth() const;
    const int &getHeighth() const;

    int getBeginX() const;
    int getEndX() const;
    int getBeginY() const;
    int getEndY() const;



    const std::vector<std::vector<bool>> &getGrid() const;

    bool operator()(size_t n, size_t k) const;



    static long overlapping(const std::vector<Cloth> &source);

private:
    void calcGrid();
};