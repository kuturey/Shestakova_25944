#include <iostream>
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

    arr = nullptr;
    g = nullptr;

    //добавление элемента в середину массива
    int* newArr = new int[size + 1];
    int mid = size / 2;
    int newValue = 999;

    for (int i = 0; i < mid; i++) newArr[i] = (i + 1) * 10;
    newArr[mid] = newValue;
    for (int i = mid; i < size; i++) newArr[i + 1] = (i + 1) * 10;

    cout << "Array after insert: ";
    for (int i = 0; i < size + 1; i++) {
        cout << newArr[i] << " ";
    }
    cout << endl;

    delete p;
    p = nullptr;
    delete[] secret;
    secret = nullptr;
    delete[] newArr;
    newArr = nullptr;

    return 0;
}