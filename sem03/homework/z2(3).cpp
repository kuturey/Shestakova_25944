#include <iostream>
#include <memory>
using namespace std;

int main() {
    //указатель на одно значение
    int* p = new int(42);

    //указатель на массив
    int size = 7;
    int* arr = new int[size];

    //заполняем массив
    for (int i = 0; i < size; i++) {
        arr[i] = (i + 1) * 10;
    }

    //выводим массив
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //Висячий указатель 
    int* g = arr;
    delete[] arr;
    arr = nullptr;

    cout << "g[0] = " << g[0] << endl;

    //опасность висячего указателя
    int* secret = new int[size];
    for (int i = 0; i < size; i++) secret[i] = 777;

    cout << "secret before write g: ";
    for (int i = 0; i < size; i++) cout << secret[i] << " ";
    cout << endl;

    //пишем через висячий g
    g[0] = -1;
    g[1] = -2;

    cout << "secret after write g: ";
    for (int i = 0; i < size; i++) cout << secret[i] << " ";
    cout << endl;

    g = nullptr;

    //исходные данные для вставки
    int* base = new int[size];
    for (int i = 0; i < size; i++) base[i] = (i + 1) * 10;

    //добавление элемента в середину массива
    int* newArr = new int[size + 1];
    int mid = size / 2;
    int newValue = 999;

    for (int i = 0; i < mid; i++)    newArr[i] = base[i];
    newArr[mid] = newValue;
    for (int i = mid; i < size; i++) newArr[i + 1] = base[i];

    cout << "Array after insert: ";
    for (int i = 0; i < size + 1; i++) {
        cout << newArr[i] << " ";
    }
    cout << endl;

    //правильное очищение памяти
    delete p;         p = nullptr;
    delete[] secret;  secret = nullptr;
    delete[] base;    base = nullptr;
    delete[] newArr;  newArr = nullptr;

    cout << endl;

    //unique_ptr единоличное владение память освобождается сама
    {
        unique_ptr<int> up = make_unique<int>(42);
        cout << *up << endl;

        unique_ptr<int[]> uarr = make_unique<int[]>(size);
        for (int i = 0; i < size; i++) uarr[i] = (i + 1) * 10;

        for (int i = 0; i < size; i++) cout << uarr[i] << " ";
        cout << endl;
    }

    //shared_ptr общее владение, счётчик ссылок
    {
        shared_ptr<int> sp1 = make_shared<int>(100);
        shared_ptr<int> sp2 = sp1;

        cout << sp1.use_count() << endl;
        cout << *sp1 << endl;

        //weak_ptr - наблюдает, но не владеет
        weak_ptr<int> wp = sp1;
        cout << wp.expired() << endl;

        sp1.reset();
        sp2.reset();
        cout << wp.expired() << endl;
    }

    //weak_ptr не даёт получить висячий указатель
    {
        shared_ptr<int> owner = make_shared<int>(555);
        weak_ptr<int> observer = owner;

        if (auto locked = observer.lock())
            cout << *locked << endl;

        owner.reset();

        if (auto locked = observer.lock())
            cout << *locked << endl;
        else
            cout << "nullptr" << endl;
    }

    return 0;
}