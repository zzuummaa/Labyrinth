#ifndef MAP
#define MAP

#include <qcoreapplication.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

void show(vector<vector<int> > cells);

void initcells(vector<vector<int> > *cells, int w, int h);
void initlabmap();

class labmap
{
private:
    int w, h;
public:
    vector<vector<int> > cells;
    labmap();
    labmap(vector<vector<int> > cells);
    void setcells(vector<vector<int> > cells);
    void loadway(int* l, int* r, int* u, int* d);
    void loadway(int *out, const int x, const int y);
    int getcell(const int x, const  int y);

};


void load(const char *filename, vector<vector<int> > *cells);
void load2(const char *filename, labmap *lmap);

#endif // MAP

