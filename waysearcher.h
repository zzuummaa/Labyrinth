#ifndef WAYSEARCHER_H
#define WAYSEARCHER_H
#include <map.h>


class waysearcher
{
public:
    int x, y;

    waysearcher(labmap lmap);
    bool go(char d);
    bool go(const int x, const int y);
    void loadway(int *out, const int x, const int y);
    void loadway(int* l, int* r, int* u, int* d);
private:
    labmap lmap;
};

#endif // WAYSEARCHER_H
