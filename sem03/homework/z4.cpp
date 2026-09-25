#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <string>
#include "temp.h"

using namespace std;

int main() {
    srand(time(0));

    const int M = 12;
    const int N = 40;

    //второй аргумент функции 
    //float delta = rand() % (2 * N + 1) - N;

    //исходные контейнеры
    array<float, M>  a;
    vector<float>    v(M);
    list<float>      l(M);
    deque<float>     d(M);

    //заполняем array
    for (int i = 0; i < M; i++) a[i] = rand() % (2 * N + 1) - N;

    //заполняем vector
    for (int i = 0; i < M; i++) v[i] = rand() % (2 * N + 1) - N;

    //заполняем list
    {
        int i = 0;
        for (auto it = l.begin(); it != l.end(); ++it, ++i)
            *it = rand() % (2 * N + 1) - N;
    }

    //заполняем deque
    for (auto& x : d) x = rand() % (2 * N + 1) - N;

    //контейнеры результатов
    vector<long> rv(M);
    list<long>   rl(M);
    deque<long>  rd(M);
    array<long, M> ra;

    //array  vector
    for (int i = 0; i < M; i++) {
        float tmp = a[i];
        rv[i] = modified::toFahrenheit<long, float>(tmp);
    }

    //vector  list
    {
        int i = 0;
        for (auto it = rl.begin(); it != rl.end(); ++it, ++i) {
            float tmp = v[i];
            *it = modified::toFahrenheit<long, float>(tmp);
        }
    }

    //list  deque
    {
        auto it = l.begin();
        for (int i = 0; i < M; i++, ++it) {
            float tmp = *it;
            rd[i] = modified::toFahrenheit<long, float>(tmp);
        }
    }

    //deque  array
    for (int i = 0; i < M; i++) {
        float tmp = d[i];
        ra[i] = modified::toFahrenheit<long, float>(tmp);
    }

    //собираем таблицу одним циклом
    string table;
    table += "| array | vector | list | deque | rv | rl | rd | ra |\n";
    table += "|---|---|---|---|---|---|---|---|\n";

    {
        auto it_l = l.begin();
        auto it_rl = rl.begin();
        for (int i = 0; i < M; i++, ++it_l, ++it_rl) {
            table += "| " + to_string(a[i]) + " | " + to_string(v[i]) + " | "
                + to_string(*it_l) + " | " + to_string(d[i]) + " | "
                + to_string(rv[i]) + " | " + to_string(*it_rl) + " | "
                + to_string(rd[i]) + " | " + to_string(ra[i]) + " |\n";
        }
    }

    ofstream fout("table.md");
    fout << table;
    fout.close();

    cout << table;

    return 0;
}