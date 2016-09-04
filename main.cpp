#include <QCoreApplication>
#include <map.h>

using namespace std;

void show(vector<vector<int> > cells, int w, int h)
{
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << cells[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << '\r';
}

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
    createfile();

    vector<vector<int> > cells;
    load("in.txt", &cells);

    int w = cells[0].size(), h = cells.size();
    initcells(&cells, w, h);

    int ways[4];
    labmap m = labmap(cells);
    m.loadway(&ways[0], &ways[1], &ways[2], &ways[3]);

    show(m.cells, w, h);
    show(ways);
}

