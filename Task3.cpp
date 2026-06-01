#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    cout << "Enter the elements of vector V1 on the first non-empty line." << '\n';
    cout << "Enter the elements of vector V2 in the remaining input." << '\n';

    // 1. Читаем первую строку, из неё — V1 (через итераторы)
    string line1;
    getline(cin, line1);
    istringstream in1(line1);
    vector<int> v1{istream_iterator<int>(in1), istream_iterator<int>()};

    // 2. Все оставшиеся числа из cin читаем сразу в V2 через итераторы
    //    (пробелы, переводы строк игнорируются — это и есть "the remaining input")
    vector<int> v2{istream_iterator<int>(cin), istream_iterator<int>()};

    // 3. Группировка V2 по последней цифре
    map<int, vector<int>> m;
    for (auto it = v2.begin(); it != v2.end(); ++it)
    {
        int last_digit = abs(*it) % 10;          // правильное вычисление последней цифры
        m[last_digit].push_back(*it);
    }

    // 4. Внутреннее объединение
    vector<pair<int, int>> v;
    for (auto it1 = v1.begin(); it1 != v1.end(); ++it1)
    {
        auto it = m.find(abs(*it1) % 10);        // ищем ключ в отображении M
        if (it == m.end())
            continue;

        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            v.push_back(make_pair(*it1, *it2));
    }

    // 5. Вывод результата
    cout << v.size() << '\n';
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << it->first << ' ' << it->second << '\n';

    return 0;
}
