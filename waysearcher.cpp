#include "waysearcher.h"

waysearcher::waysearcher(labmap lmap)
{
    this->lmap = lmap;
}

/**
 * @brief go
 * @param x |новые координаты
 * @param y |на карте
 * @return true - удачное перемещение
 *         false- не удачное
 */
bool waysearcher::go(const int x, const int y) {
    if (lmap.getcell(x, y) != -1) {
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
bool waysearcher::go(char d)
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
void waysearcher::loadway(int *out, const int x, const int y)
{
    *out = lmap.getcell(x, y);
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
void waysearcher::loadway(int* l, int* r, int* u, int* d)
{
    loadway(l, x-1, y);
    loadway(r, x+1, y);
    loadway(u, x, y+1);
    loadway(d, x, y-1);
}

