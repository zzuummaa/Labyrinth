#include <map.h>

/**
 * @brief generateEdgeCell генерирует позицию на краю карты
 * @param lmap карта, для которой генерируется клетка
 * @param x, y - сгенерированные значения
 */
void generateEdgeCell(const labmap *lmap, int *x, int *y)
{
    int w = (*lmap->cells)[0].size();
    int h = lmap->cells->size();
    int tmp;

    if (rand() % 2) {
        *y = rand() % h;
        if (rand() % 2) {
            *x = 0;
        } else {
            *x = w - 1;
        }
    } else {
        *x = rand() % w;
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

bool isValidCellFirst(labmap *lmap, const int x, const int y)
{
    int z = beside(lmap, 1, x, y)
          + beside(lmap, 2, x, y)
          + beside(lmap, 3, x, y);

    if (!z) return false;

    if (beside(lmap, -1, x, y)) return false;

    if (diag(lmap, 1, x, y)) return false;

    return true;
}

void generate(labmap *lmap, int width, int height)
{
    vector<vector<int> > *cells = new vector<vector<int> >;
    initcells(cells, width, height);

    lmap->setcells(cells);

    int *x = new int(0);
    int *y = new int(0);

    srand(time(NULL));

    generateEdgeCell(lmap, x, y);
    lmap->setcell(*x, *y, 2);

    do {
        generateEdgeCell(lmap, x, y);
    } while (beside(lmap, 2, *x, *y));
    lmap->setcell(*x, *y, 3);

    for (int i = 0; i < lmap->getHeight(); i++) {
        for (int j = 0; j < lmap->getWidth(); j++) {
            if (isValidCellFirst(lmap, j, i))
                lmap->setcell(j, i, 1);
        }
    }
}
