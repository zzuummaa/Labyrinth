#include <map.h>

void show(vector<vector<int> > *cells)
{
    for (int i = 0; i < cells->size(); i++) {
        for (int j = 0; j < (*cells)[i].size(); j++) {
            cout << (*cells)[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << '\r';
}

void initcells(vector<vector<int> > *cells, int w, int h)
{
    for (int i = 0; i < h; i++) {
        (*cells).push_back(vector<int>());
        for (int j = 0; j < w; j++) {
            (*cells)[i].push_back(0);
        }
    }
}

/**
 * @brief isinnerelement Проверяет, находится ли позиция (x, y) внутри двухмерного вектора
 * @param cells
 * @param x
 * @param y
 * @return
 */
bool isinnerelement(const vector<vector<int> > *cells, int x, int y)
{
    if (cells->size() == 0) return false;

    return (x < cells[0].size() & x >= 0)
         & (y < cells->size()    & y >= 0);
}

labmap::labmap()
{
    labmap(new vector<vector<int> >);
}

labmap::labmap(int width, int height)
{
    vector<vector<int> > *cells = new vector<vector<int> >;
    initcells(cells, width, height);

    this->cells = cells;
}

labmap::labmap(vector<vector<int> > *cells)
{
    this->cells = cells;
}

void labmap::setcells(vector<vector<int> > *cells)
{
    this->cells = cells;
}

int labmap::getcell(const int x, const int y)
{
    if (isinnerelement(cells, x, y)) {
        return (*cells)[y][x];
    } else {
        return -1;
    }
}

bool labmap::setcell(const int x, const int y, const int val)
{
    if (isinnerelement(cells, x, y)) {
        (*cells)[y][x] = val;
        return true;
    } else {
        return false;
    }
}

int labmap::getWidth()
{
    if (!cells->size()) return 0;
    else               return (*cells)[0].size();
}

int labmap::getHeight()
{
    return cells->size();
}
