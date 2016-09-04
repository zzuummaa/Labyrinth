#include <map.h>

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
bool isinnerelement(const vector<vector<int> > cells, int x, int y)
{
    return (x < cells[0].size() & x >= 0)
         & (y < cells.size()    & y >= 0);
}

void initlabmap()
{
    cout << "init labmap\n";

    vector<vector<int> > cells;
    initcells(&cells, 3, 3);
    labmap m = labmap(cells);

    cout << "x = " << m.x << "; y = " << m.y << "\n";
    m.go('u');
    cout << "went down\n";
    cout << "x = " << m.x << "; y = " << m.y << "\n";
}

labmap::labmap(vector<vector<int> > cells)
{
    this->cells = cells;
}

void labmap::setcells(vector<vector<int> > cells)
{
    this->cells = cells;
}

/**
 * @brief go
 * @param x |новые координаты
 * @param y |на карте
 * @return true - удачное перемещение
 *         false- не удачное
 */
bool labmap::go(const int x, const int y) {
    if (isinnerelement(cells, x, y)) {
        this->x = x;
        this->y = y;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief go
 * @param d направление перемещения
 * @return true - удачное перемещение
 *         false- не удачное
 */
bool labmap::go(char d)
{
    int x = this->x, y = this->y;

    if (d == 'u') y++;
    if (d == 'd') y--;
    if (d == 'r') x++;
    if (d == 'l') x--;

    return go(x, y);
}

/**
 * @brief loadway Загружает точку в указатель
 * @param out указатель, в который загружается значение
 * @param point значение, которое загружается
 */
void labmap::loadway(int *out, const int x, const int y)
{
    if (isinnerelement(cells, x, y)) {
        *out = cells[y][x];
    } else {
        *out = -1;
    }
}

/**
 * @brief loadways
 *
 * Загружает информацию состояния пути в разных направлениях
 * @param l
 * @param r
 * @param u
 * @param d
 */
void labmap::loadway(int* l, int* r, int* u, int* d)
{
    loadway(l, x-1, y);
    loadway(r, x+1, y);
    loadway(u, x, y+1);
    loadway(d, x, y-1);
}
