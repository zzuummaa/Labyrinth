#include <QCoreApplication>
#include <labyrinth.h>
#include <waysearcher.h>
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
    testmapsize();
    cout << "\n";

    labmap *lmap = new labmap();
    load2("in.txt", lmap);
    cout << "loded cells:\n";
    show(lmap->cells);
    cout << '\n';

    waysearcher ws = waysearcher(lmap);

    int ways[4];
    ws.loadway(&ways[0], &ways[1], &ways[2], &ways[3]);

    show(ways);
    cout << '\n';

    cout << "Generate labmap:\n";
    generate(lmap, 20, 20);
    show(lmap->cells);
    cout << '\n';

    cout << "search way in labmap:\n";
    waysearcher wsearcher = waysearcher(lmap);
    if (searchway(&wsearcher) == true) {
        show(wsearcher.opencells.cells);
    } else {
        cout << "Way not found!\n";
    }
    cout << '\n';

    cout << "input command 'e' to exit or 's' to save labyrinth: ";
    char c;
    cin >> c;
    if (c == 's') save("out.txt", lmap);


}

