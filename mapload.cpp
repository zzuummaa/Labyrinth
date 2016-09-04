#include <map.h>

void load(const char *filename, vector<vector<int> > *cells)
{
    ifstream in(filename);
    if (!in) {
        cout << "can't read file\n";
        return;
    }

    int i1, i2;
    in >> i1;
    in >> i2;
    cout << "read values: " << i1 << ' ' << i2 << '\n';

    in.close();
}

void load2(const char *filename, vector<vector<int> > *cells)
{
    FILE f = FILE(filename);

    int i;
    while(fscanf(f, "%d ", i)) cout << i << ' ';

    cout << '\n';
    f.close();
}
