#include <QCoreApplication>
#include <labyrinth.h>
#include <sstream>

using namespace std;

void testmapsize()
{
    cout << "Test labmap size:\n";

    labmap lmap = labmap(2, 1);
    for (int i = 0; i < lmap.getWidth(); i++) {
        lmap.setcell(i, 0, 1);
    }

    show(lmap.cells);
}

void testss()
{
    int a = 10;
    stringstream ss;

    ss << a << ' ' << '\n';
    ss << a;

    cout << ss.str();
    //cout << ss.str();

    cout << '\n';
}

void show(const int ways[])
{
    cout << "l = " << ways[0] << "; ";
    cout << "r = " << ways[1] << "; ";
    cout << "u = " << ways[2] << "; ";
    cout << "d = " << ways[3] << "\n";
}

void createfile()
{
    ofstream out("in.txt");
    if (!out) {
        cout << "Can't open a file" << "\n";
        return;
    }

    out << 2 << ' ' << '\n';
    out << 1;


    out.close();
}

int main()
{
    //createfile();

    vector<vector<int> > *cells;

    //int w = cells[0].size(), h = cells.size();
    //initcells(&cells, w, h);

    labmap *lmap = new labmap(cells);
    load2("in.txt", lmap);
    cout << "loded cells:\n";
    show(lmap->cells);
    cout << '\n';

    waysearcher ws = waysearcher(lmap);

    int ways[4];
    ws.loadway(&ways[0], &ways[1], &ways[2], &ways[3]);

    show(ways);
    cout << '\n';

    generate(lmap, 12, 6);
    show(lmap->cells);
    cout << '\n';

    testmapsize();

    char c;
    cin >> c;
    if (c == 's') save("out.txt", lmap);


}

