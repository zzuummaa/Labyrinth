#ifndef MAP
#define MAP

#include <qcoreapplication.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

void show(vector<vector<int> > *cells);

void initcells(vector<vector<int> > *cells, int w, int h);
void initlabmap();

/**
 * @brief The labmap class
 *
 * Легенда:
 *-1 - выход за пределы карты
 * 0 - стена
 * 1 - проход
 * 2 - вход
 * 3 - выход
 * 4 - маршрут от входа к выходу
 */
class labmap
{
private:
public:
    int w, h;

    vector<vector<int> > *cells;
    labmap();
    labmap(int width, int height);
    labmap(vector<vector<int> > *cells);

    int getcell(const int x, const  int y);
    bool setcell(const int x, const int y, const int val);
    void setcells(vector<vector<int> > *cells);

    int getWidth();
    int getHeight();
};

void generate(labmap *lmap, int width, int height);

void load(const char *filename, vector<vector<int> > *cells);
void load2(const char *filename, labmap *lmap);

void save(const char *filename, labmap *lmap);

#endif // MAP

