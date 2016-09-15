#ifndef WAYSEARCHER_H
#define WAYSEARCHER_H
#include <map.h>

class waysearcher
{
public:
    int x, y;
    labmap *lmap;
    labmap opencells;

    waysearcher(labmap *lmap);
    bool go(char d);
    bool go(const int x, const int y);

    bool loadway(int *out, const int x, const int y);
    int loadway(int* l, int* r, int* u, int* d);

    bool closeway(int way[2], const int x, const int y);
    int closecells(int ways[4][2], int cell[]);

    bool mark(const int m);
    bool mark(const int x, const int y, const int mark);
    int getmark(const int x, const int y);
    int getmark();

private:
};

bool searchway(waysearcher *wsearcher);

#endif // WAYSEARCHER_H
