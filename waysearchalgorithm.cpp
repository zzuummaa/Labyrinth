#include <map.h>
#include <waysearcher.h>

/**
 * @brief searchway находит клетку выхода, начиная поиск с клетки с координатами thiscell.
 * Добавляет отметки о прохождении клеток в wsearcher.
 * @param wsearcher содержит информаццию об исследованных клетках (0 - неизвестная, 1 - отркытая, 2 - путь к выходу)
 * @return true  - выход найден
 *         false - выход не найден
 */
bool searchway(waysearcher *wsearcher, int thiscell[2])
{   
    int cell[2];
    cell[0] = thiscell[0];
    cell[1] = thiscell[1];

    int cellnum = wsearcher->lmap->getcell(cell[0], cell[1]);

    if (cellnum == 3) return true;

    if (wsearcher->getmark(cell[0], cell[1]) != 0) {
        return false;
    } else {
        wsearcher->mark(cell[0], cell[1], 1);
    }

    if (cellnum == 0 || cellnum == -1) return false;

    int ways[4][2];
    wsearcher->closecells(ways, thiscell);

    for (int i = 0; i < 4; i++) {
        if (searchway(wsearcher, ways[i]) == true) {
            wsearcher->mark(cell[0], cell[1], 2);
            return true;
        }
    }
}

/**
 * @brief searchway ищет путь на карте, от клетки с номером 2 до клетки с номером 3, записывая путь в параметр way
 */
bool searchway(waysearcher *wsearcher)
{
    labmap *lmap = wsearcher->lmap;

    for (int i=0; i < lmap->getWidth(); i++) {
        for (int j=0; j < lmap->getHeight(); j++) {
            if (lmap->getcell(i, j) == 2) {

                int startcell[2];

                startcell[0] = i;
                startcell[1] = j;

                return searchway(wsearcher, startcell);
            }
        }
    }
}
