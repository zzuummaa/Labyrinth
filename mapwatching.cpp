#include "mapwatching.h"
#include <qcoreapplication.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/*void initcells(int *cells[][], int w, int h)
{
    *cells = new int[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cells[i][j] = 0;
        }
    }
}*/

void initcells(vector<vector<int> > *cells, int w, int h)
{
    for (int i = 0; i < h; i++) {
        (*cells).push_back(vector<int>());
        for (int j = 0; j < w; j++) {
            (*cells)[i].push_back(0);
        }
    }
}

/**
 * @brief isinnerelement Проверяет, находится ли позиция (x, y) внутри двухмерного вектора
 * @param cells
 * @param x
 * @param y
 * @return
 */
bool isinnerelement(const vector<vector<int> > cells, int x, int y)
{
    return (x < cells[0].size() & x >= 0)
         & (y < cells.size()    & y >= 0);
}

/**
 * @brief The map class
 *
 * Содержит в себе карту лабиринта в виде двухмерного вектора int значений
 *
 * Обозначения на карте:
 *-1 - конец карты
 * 0 - нет прохода
 * 1 - есть проход
 * 2 - выход
 * 3 - вход
 */
class labmap
{
private:
    vector<vector<int> > cells;
    int w, h;

    int x, y;

    void loadcellsfromfile(FILE *f, int w, int h)
    {
        int *a = 0;
        char s[2];

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                fscanf(f, "%d ", &a);
                cells[i][j] = *a;
            }
            fscanf(f, "%s", s);
        }
    }

    /**
     * @brief initpos устанавливает значение (x, y), находя точку
     * входа на карте (т.е клетку со значением 3)
     */
    void initinpos()
    {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (cells[i][j] == 3) {
                    x = j;
                    y = i;
                }
            }
        }
    }

public:
    labmap()
    {
    }

    void setcells(vector<vector<int> > cells)
    {
        this->cells = cells;
    }

    labmap(vector<vector<int> > cells)
    {

        this->cells = cells;
        this->h = cells.size();
        this->w = cells[0].size();
    }

    void init(FILE *f, int w, int h)
    {
        this->w = w;
        this->h = h;

        //initcells(cells, w, h);
        loadcellsfromfile(f, w, h);

        initinpos();
    }

    /**
     * @brief loadway Загружает точку в указатель
     * @param out указатель, в который загружается значение
     * @param point значение, которое загружается
     */
    void loadway(int *out, const int x, const int y)
    {
        if (isinnerelement(cells, x, y)) {
            *out = cells[y][x];
        } else {
            *out = -1;
        }
    }

    /**
     * @brief loadways
     *
     * Загружает информацию состояния пути в разных направлениях
     * @param l
     * @param r
     * @param u
     * @param d
     */
    void loadway(int* l, int* r, int* u, int* d)
    {
        loadway(l, x-1, y);
        loadway(r, x+1, y);
        loadway(u, x, y+1);
        loadway(d, x, y-1);
    }

    /**
     * @brief go
     * @param x |новые координаты
     * @param y |на карте
     * @return true - удачное перемещение
     *         false- не удачное
     */
    bool go(const int x, const int y) {
        if (isinnerelement(cells, x, y)) {
            this->x = x;
            this->y = y;
            return true;
        } else {
            return false;
        }
    }

    /**
     * @brief go
     * @param d направление перемещения
     * @return true - удачное перемещение
     *         false- не удачное
     */
    bool go(char d)
    {
        int x = this->x, y = this->y;

        if (d == 'u') y++;
        if (d == 'd') y--;
        if (d == 'r') x++;
        if (d == 'l') x--;

        return go(x, y);
    }
};

void initlabmap()
{
    labmap m;
    cout << "init labmap\n";

    vector<vector<int> > cells;
    initcells(&cells, 3, 3);

    m.setcells(cells);
    m.go('d');
    cout << "went down\n";
}
