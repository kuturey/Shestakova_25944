#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

// Читает целые числа из файла и возвращает их в виде vector<int>.
std::vector<int> readFile(const std::string& filename)
{
    std::vector<int> numbers;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cout << "Cannot open file: " << filename << '\n';
        return numbers;
    }

    std::string line;

    // Читаем файл построчно.
    while (std::getline(file, line))
    {
        std::replace(line.begin(), line.end(), ',', ' ');
        std::stringstream stream(line);

        int number;

        while (stream >> number)
        {
            numbers.push_back(number);
        }
    }

    return numbers;
}


// Первый способ подсчета количества каждого числа
void printCountsFor(const std::vector<int>& numbers)
{
    // Храним числа, для которых количество уже было посчитано
    std::vector<int> checked;

    for (int number : numbers)
    {
        bool alreadyChecked = false;

        // Вручную ищем число среди уже обработанных.
        for (int checkedNumber : checked)
        {
            if (checkedNumber == number)
            {
                alreadyChecked = true;
            }
        }

        // Если число уже считали, переходим к следующему элементу.
        if (alreadyChecked)
        {
            continue;
        }

        // Счетчик количества текущего числа
        int amount = 0;

        // Еще раз проходим весь вектор и считаем совпадения
        for (int value : numbers)
        {
            if (value == number)
            {
                amount++;
            }
        }

        // Выводим число и количество его появлений
        std::cout << number << ": " << amount << '\n';

        // Запоминаем, что это число уже обработано
        checked.push_back(number);
    }
}


// Второй способ решения
void printCountsAlgorithm(const std::vector<int>& numbers)
{
    // Уже обработанные значения
    std::vector<int> checked;

    for (int number : numbers)
    {
        // std::find ищет number в диапазоне [begin, end)
        // Если найдено значение, результат будет не равен end()
        // Значит число уже обрабатывалось и его можно пропустить
        if (std::find(checked.begin(), checked.end(), number) != checked.end())
        {
            continue;
        }

        // std::count считает, сколько раз number встречается
        // во всем диапазоне numbers
        int amount = static_cast<int>(
            std::count(numbers.begin(), numbers.end(), number)
        );

        std::cout << number << ": " << amount << '\n';

        // Добавляем число в список уже обработанных
        checked.push_back(number);
    }
}


int main()
{
    std::vector<int> vector1 = readFile("s04_v1_44_1.txt");
    std::vector<int> vector2 = readFile("s04_v1_44_2.txt");

    if (vector1.empty() || vector2.empty())
    {
        return 1;
    }

    std::vector<int> first;
    std::vector<int> second;

    // Сравниваем размеры векторов.
    if (vector1.size() >= vector2.size())
    {
        first = vector1;
        second = vector2;
    }
    else
    {
        first = vector2;
        second = vector1;
    }

    // Выводим количество элементов каждого вектора
    std::cout << "First vector size: " << first.size() << '\n';
    std::cout << "Second vector size: " << second.size() << "\n\n";

    // Задание 4.I, пункт 3а
    // Подсчет количества каждого числа через for
    std::cout << "Counts in first vector, for:\n";
    printCountsFor(first);

    std::cout << "\nCounts in second vector, for:\n";
    printCountsFor(second);

    // Задание 4.I, пункт 3б
    // Подсчет количества каждого числа средствами стандартной библиотеки
    std::cout << "\nCounts in first vector, std::count:\n";
    printCountsAlgorithm(first);

    std::cout << "\nCounts in second vector, std::count:\n";
    printCountsAlgorithm(second);

    // Задание 4.I, пункт 4
    // Первый вариант вычисления суммы
    int sumFirst1 = std::accumulate(first.begin(), first.end(), 0);
    int sumSecond1 = std::accumulate(second.begin(), second.end(), 0);

    // Второй вариант вычисления суммы
    int sumFirst2 = std::accumulate(
        first.begin(),
        first.end(),
        0,
        [](int sum, int number)
        {
            return sum + number;
        }
    );

    int sumSecond2 = std::accumulate(
        second.begin(),
        second.end(),
        0,
        [](int sum, int number)
        {
            return sum + number;
        }
    );

    std::cout << "\nFirst vector sum, variant 1: "
              << sumFirst1 << '\n';

    std::cout << "Second vector sum, variant 1: "
              << sumSecond1 << '\n';

    std::cout << "First vector sum, variant 2: "
              << sumFirst2 << '\n';

    std::cout << "Second vector sum, variant 2: "
              << sumSecond2 << '\n';

    // Задание 4.I, пункт 5
    // Сумма первых десяти элементов без циклов
    int firstTen = std::accumulate(
        first.begin(),
        first.begin() + 10,
        0
    );

    int secondTen = std::accumulate(
        second.begin(),
        second.begin() + 10,
        0
    );

    std::cout << "\nFirst 10 sum in first vector: "
              << firstTen << '\n';

    std::cout << "First 10 sum in second vector: "
              << secondTen << '\n';

    // Задание 4.II, пункт 1
    // Найти сумму чисел, модуль которых больше 22.
    int resultFirst = std::accumulate(
        first.begin(),
        first.end(),
        0,
        [](int sum, int number)
        {
            if (std::abs(number) > 22)
            {
                return sum + number;
            }

            return sum;
        }
    );

    int resultSecond = std::accumulate(
        second.begin(),
        second.end(),
        0,
        [](int sum, int number)
        {
            if (std::abs(number) > 22)
            {
                return sum + number;
            }

            return sum;
        }
    );

    std::cout << "\nSum of |x| > 22 in first vector: "
              << resultFirst << '\n';

    std::cout << "Sum of |x| > 22 in second vector: "
              << resultSecond << '\n';

    // Задание 4.II, пункт 2
    // Находим числа второго, меньшего вектора,
    // которые встречаются в нем 2 и более раз.
    std::vector<int> repeatedSecond;

    for (int number : second)
    {
        if (std::count(second.begin(), second.end(), number) >= 2 &&
            std::find(
                repeatedSecond.begin(),
                repeatedSecond.end(),
                number
            ) == repeatedSecond.end())
        {
            repeatedSecond.push_back(number);
        }
    }

    // Теперь находим числа первого вектора,
    // встречающиеся более 3 раз.
    std::vector<int> repeatedFirst;

    for (int number : first)
    {
        if (std::count(first.begin(), first.end(), number) > 3 &&
            std::find(
                repeatedFirst.begin(),
                repeatedFirst.end(),
                number
            ) == repeatedFirst.end())
        {
            repeatedFirst.push_back(number);
        }
    }

    std::cout << "\nSecond vector, repeated 2 or more times:\n";

    for (int number : repeatedSecond)
    {
        std::cout << number << ' ';
    }

    std::cout << '\n';

    std::cout << "First vector, repeated more than 3 times:\n";

    for (int number : repeatedFirst)
    {
        std::cout << number << ' ';
    }

    std::cout << '\n';

    // Задание 4.II, пункт 3а
    // Первый способ: обычные циклы for.
    std::cout << "\nCommon repeated numbers, for:\n";

    for (int number : repeatedSecond)
    {
        int firstCount = 0;
        int secondCount = 0;

        for (int value : first)
        {
            if (value == number)
            {
                firstCount++;
            }
        }

        if (firstCount > 3)
        {
            for (int value : second)
            {
                if (value == number)
                {
                    secondCount++;
                }
            }

            std::cout << number
                      << ": first = " << firstCount
                      << ", second = " << secondCount
                      << '\n';
        }
    }

    // Задание 4.II, пункт 3б
    // Второй способ: std::for_each + lambda.
    std::cout
        << "\nCommon repeated numbers, std::for_each + lambda:\n";

    std::for_each(
        repeatedSecond.begin(),
        repeatedSecond.end(),
        [&first, &second](int number)
        {
            int firstCount = static_cast<int>(
                std::count(
                    first.begin(),
                    first.end(),
                    number
                )
            );

            if (firstCount > 3)
            {
                int secondCount = static_cast<int>(
                    std::count(
                        second.begin(),
                        second.end(),
                        number
                    )
                );

                std::cout << number
                          << ": first = " << firstCount
                          << ", second = " << secondCount
                          << '\n';
            }
        }
    );

    return 0;
}
