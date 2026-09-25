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

    //исходные контейнеры
    array<float, M>  a;
    vector<float>    v(M);
    list<float>      l(M);
    deque<float>     d(M);
    
    //заполняем array
    for (int i = 0; i < M; i++) {
        a[i] = rand() % (2 * N + 1) - N;
        v[i] = rand() % (2 * N + 1) - N;
    }

    //заполняем list
    
    int i = 0;
    for (list<float>::iterator it = l.begin(); it != l.end(); ++it, ++i) {
        *it = rand() % (2 * N + 1) - N;
    }

    //заполняем deque
    for (float& x : d) x = rand() % (2 * N + 1) - N;

    //контейнеры результатов
    vector<long> rv(M);
    list<long>   rl(M);
    deque<long>  rd(M);
    array<long, M> ra;

    //array  vector
    for (int i = 0; i < M; i++) {
        rv[i] = modified::toFahrenheit<long, float>(a[i]);
    }

    //vector  list
    {
        int i = 0;
        for (list<long>::iterator it = rl.begin(); it != rl.end(); ++it, ++i) {
            float tmp = v[i];
            *it = modified::toFahrenheit<long, float>(v[i]);
        }
    }

    //list  deque
    {
        list<float>::iterator it = l.begin();
        for (int i = 0; i < M; i++, ++it) {
            float tmp = *it;
            rd[i] = modified::toFahrenheit<long, float>(*it);
        }
    }

    //deque  array
    for (int i = 0; i < M; i++) {
        ra[i] = modified::toFahrenheit<long, float>(d[i]);
    }

    //собираем таблицу одним циклом
    string table;
    table += "| array | vector | list | deque | rv | rl | rd | ra |\n";
    table += "|---|---|---|---|---|---|---|---|\n";

    {
        list<float>::iterator it_l = l.begin();
        list<long>::iterator it_rl = rl.begin();
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