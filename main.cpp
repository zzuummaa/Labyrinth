#include <QCoreApplication>
#include <labyrinth.h>

using namespace std;

void show(const int ways[])
{
    cout << "l = " << ways[0] << "; ";
    cout << "r = " << ways[1] << "; ";
    cout << "u = " << ways[2] << "; ";
    cout << "d = " << ways[3];

    cout << '\n';
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

    vector<vector<int> > cells;

    //int w = cells[0].size(), h = cells.size();
    //initcells(&cells, w, h);

    labmap *lmap = new labmap(cells);
    load2("in.txt", lmap);
    cout << "loded cells:\n";
    show((*lmap).cells);
    cout << '\n';

    waysearcher ws = waysearcher(*lmap);

    int ways[4];
    ws.loadway(&ways[0], &ways[1], &ways[2], &ways[3]);

    show(ways);
}

