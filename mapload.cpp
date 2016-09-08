#include <map.h>
#include <sstream>

void parseNums(string line, vector<vector<int> > *cells);

void save(const char *filename, labmap *lmap)
{
    ofstream f(filename);
    vector<vector<int> > *cells = lmap->cells;
    string data;

    for (int i = 0; i < (*cells).size(); i++) {
        stringstream ss;
        for (int j = 0; j < (*cells)[i].size(); j++) {
            ss << (*cells)[i][j] << ' ';
        }
        data.append(ss.str().substr(0, ss.str().size()-1));
        data.append("\n");
    }
    data.replace(0, data.size()-1, data.substr(0, data.size()-1));

    f << data;
    f.close();
}

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

void load2(const char *filename, labmap *lmap)
{
    string line;
    fstream f(filename);
    vector<vector<int> > *cells = new vector<vector<int> >();

    cout << "read data:\n";
    while (f.good()) {
        getline(f, line);
        parseNums(line, cells);
        cout << line << '\n';
    }

    (*lmap).cells = cells;
    f.close();
}

/**
 * @brief parseDigits выделяет число из строки line располагающееся от start до end
 * @return это число
 */\
int parseDigits(string line, const int start, const int end)
{
    if (start < end)
        return atoi(line.substr(start, end).c_str());
    else
        throw runtime_error("invalid indexes. start >= end");
}

/**
 * @brief parseNums создает новый массив в матрице и добавляет туда числа из строки
 * @param line
 * @param cells
 */
void parseNums(string line, vector<vector<int> > *cells)
{
    int start = 0;
    int end = 1;

    line.append(" ");

    (*cells).push_back(vector<int>());

    while ((end = line.find(' ', start)) != -1) {
        //Временная заглушка для последнего массива
        if (end == 0) break;

        int tmp = parseDigits(line, start, end);

        //Вставляем элемент в последнюю строку, последним
        (*cells)[(*cells).size() - 1].push_back(tmp);

        start = end + 1;
    }

    //
    if ( (*cells)[(*cells).size() - 1].size() == 0){
        (*cells).resize( (*cells).size() - 1 );
    }
}
