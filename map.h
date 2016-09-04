#ifndef MAP
#define MAP

#include <qcoreapplication.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

void initcells(vector<vector<int> > *cells, int w, int h);
void initlabmap();

void load(const char *filename, vector<vector<int> > *cells);

class labmap
{
private:
    int w, h;
public:
    vector<vector<int> > cells;
    int x, y;
    labmap(vector<vector<int> > cells);
    void setcells(vector<vector<int> > cells);
    void loadway(int* l, int* r, int* u, int* d);
    void loadway(int *out, const int x, const int y);
    bool go(char d);
    bool go(const int x, const int y);
};

#endif // MAP

