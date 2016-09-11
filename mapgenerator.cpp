#include <map.h>
#include <list>

/**
 * @brief generateEdgeCell генерирует позицию на краю карты исключая угловые клетки
 * (0;0), (w;h), (0, h), (w, 0)
 * @param lmap карта, для которой генерируется клетка
 * @param x, y - сгенерированные значения
 */
void generateEdgeCell(const labmap *lmap, int *x, int *y)
{   
    int w = (*lmap->cells)[0].size();
    int h = lmap->cells->size();

    if (w < 3 && h < 3) {
        string *msg = new string("invalid lmap size:");
        //msg->append(" width=").append(to_string(w)).append(" height=").append(to_string(h));

        throw 0;
    }

    if (rand() % 2) {
        *y = rand() % (h-2) - 1;
        if (rand() % 2) {
            *x = 0;
        } else {
            *x = w - 1;
        }
    } else {
        *x = rand() % (w-2) - 1;
        if (rand() % 2) {
            *y = 0;
        } else {
            *y = h - 1;
        }
    }
}

/**
 * @brief beside Проверяет нличие элемента c номером besidenum
 * рядом с элементом (x, y)
 * @param lmap
 * @param besidenum
 * @param x
 * @param y
 * @return
 */
int beside(labmap *lmap, const int besidenum, const int x, const int y)
{
    int count = 0;

    if (lmap->getcell(x+1, y) == besidenum) count++;
    if (lmap->getcell(x-1, y) == besidenum) count++;
    if (lmap->getcell(x, y+1) == besidenum) count++;
    if (lmap->getcell(x, y-1) == besidenum) count++;

    return count;
}

/**
 * @brief beside Проверяет нличие элемента c номером diagnum
 * рядом по диагонали от элемента (x, y). Т.е в (x+1, y+1), (x+1, y-1),
 * (x-1, y+1), (x-1, y-1) позициях
 * @param lmap
 * @param diagnum номер искомого элемента
 * @param x
 * @param y
 * @return
 */
int diag(labmap *lmap, const int diagnum, const int x, const int y)
{
    int count = 0;

    if (lmap->getcell(x+1, y+1) == diagnum) count++;
    if (lmap->getcell(x+1, y+1) == diagnum) count++;
    if (lmap->getcell(x-1, y+1) == diagnum) count++;
    if (lmap->getcell(x-1, y-1) == diagnum) count++;

    return count;
}

bool isfourth(labmap *lmap, const int x, const int y, const int dx, const int dy)
{
    if (lmap->getcell(x+dx, y+dy) == 1
     && lmap->getcell(x+dx, y   ) == 1
     && lmap->getcell(x,    y+dy) == 1) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief isfourth Проверяет, сделает ли данная клетка квадрат из 4-х клеток с номером 1
 * @param lmap
 * @param x
 * @param y
 * @return
 */
bool isfourth(labmap *lmap, const int x, const int y)
{
    if (isfourth(lmap, x, y,  1,  1)) return true;
    if (isfourth(lmap, x, y,  1, -1)) return true;
    if (isfourth(lmap, x, y, -1,  1)) return true;
    if (isfourth(lmap, x, y, -1, -1)) return true;

    return false;
}

/**
 * @brief isValidCellFirst Проверяет, можно ли сгенерировать в месте с индексом
 * (x, y) клетку с номером 1
 * @param lmap
 * @param x
 * @param y
 * @return true  - можно  сгенерировать клетку 1
 *         false - нельзя сгенерировать клетку 1
 */
bool isValidCellFirst(labmap *lmap, const int x, const int y)
{
    //int z = beside(lmap, 1, x, y)
    //      + beside(lmap, 2, x, y)
    //      + beside(lmap, 3, x, y);

    //if (!z) return false;

    //if (beside(lmap, -1, x, y)) return false;

    if (diag(lmap, 1, x, y)) return false;

    return true;
}

/**
 * @brief generatecell Генерирует клетку со значением val на карте,
 * если в клетке (x, y) была клетка со значением 0
 * @param lmap
 * @param val
 * @param x
 * @param y
 * @return true  - удалось сгенерировать
 *         false - не удалось сгенерировать
 */
bool generatecell(labmap *lmap, const int val, const int x, const int y)
{
    if (lmap->getcell(x, y) == 0) {
        lmap->setcell(x, y, val);
        return true;
    } else {
        return false;
    }
}

void generatetunnel(labmap *lmap, const int x, const int y)
{
    if (!isfourth(lmap, x, y) && generatecell(lmap, 1, x, y)) {
        generatetunnel(lmap, x+1, y);
        generatetunnel(lmap, x-1, y);
        generatetunnel(lmap, x, y+1);
        generatetunnel(lmap, x, y-1);
    }
}

/**
 * @brief generateexit Генерирует клетку выхода из лабиринта (номер 3), заменяя случайным образом одну из клеток с номером 1
 * @param lmap
 * @return
 */
bool generateexit(labmap *lmap)
{
    int elemcount = 0;

    for (int i=0; i < lmap->getWidth(); i++) {
        for (int j=0; j < lmap->getHeight(); j++) {
            if (lmap->getcell(i, j) == 1)
                elemcount++;
        }
    }

    int numofelem = rand() % elemcount;
    int x = -1;
    int y = -1;

    for (int i=0; i < lmap->getWidth(); i++) {
        for (int j=0; j < lmap->getHeight(); j++) {
            if (lmap->getcell(i, j) != 1) continue;

            if (numofelem == 0) {
                x = i;
                y = j;
            } else {
                numofelem--;
            }
        }
    }

    if (x == -1 && y == -1) {
        return false;
    }

    lmap->setcell(x, y, 3);

    return true;
}

/**
 * @brief generate Генерирует карту размера [width x height]
 * @param lmap
 * @param width
 * @param height
 */
void generate(labmap *lmap, int width, int height)
{
    vector<vector<int> > *cells = new vector<vector<int> >;
    initcells(cells, width, height);

    lmap->setcells(cells);

    int *x = new int(0);
    int *y = new int(0);

    srand(time(NULL));

    generateEdgeCell(lmap, x, y);
    generatetunnel(lmap, *x, *y);
    lmap->setcell(*x, *y, 2);

    generateexit(lmap);
}
