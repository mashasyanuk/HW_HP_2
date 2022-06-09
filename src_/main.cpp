#include "MyInt.h"
#include <functional>
#include <iostream>
#include <ctime>
#include <vector>
#include <map>
using namespace std;

int main()
{
    // 1.
    vector<MyInt> vec1(10);
    srand(std::time(nullptr));
    for (int i = 0; i < 10; i++)
    {
        vec1[i] = MyInt(rand() % 100 - 50);
    }

    // 2.
    sort(vec1.begin(), vec1.end(), greater<vector<MyInt>::value_type>());

    // 3.
    cout << "<контейнер #1> содержит: ";
    copy(vec1.begin(), vec1.end(), ostream_iterator<MyInt>(cout, " "));
    cout << '\n';

    // 4.
    cout << "Найти в <контейнерt #1> первое число меньшее: ";
    vector<MyInt>::value_type i;
    cin >> i;
    vector<MyInt>::iterator it = find_if(vec1.begin(), vec1.end(),
        bind2nd(less<vector<MyInt>::value_type>(), i));
    if (it != vec1.end())
        cout << *it << '\n';
    else
        cout << "Не найдено\n";

    // 5.
    map<MyInt, MyInt> map2;
    for_each(vec1.begin(), vec1.end(),
        [&map2](vector<MyInt>::value_type i) {
            if (i > MyInt(0))
                map2.insert(make_pair(i, i));
        });

    // 6.
    cout << "<контейнер #2> содержащий только положительные элементы из <контейнер #1>: ";
    for (auto i : map2)
        cout << i.first << ' ';
    cout << '\n';

    // 7.
    sort(vec1.begin(), vec1.end(), std::less<vector<MyInt>::value_type>());


    // 8.
    cout << "Отсортированный по возрастанию <контейнер #1>: ";
    copy(vec1.begin(), vec1.end(), ostream_iterator<MyInt>(cout, " "));
    cout << '\n';
    cout << "Отсортированный по возрастанию <контейнер #2>: ";
    for (auto i : map2)
        cout << i.first << ' ';
    cout << '\n';
    std::cout << '\n';

    // 9.
    vector<MyInt> vec3 = vec1 ;
    for (auto i : map2)
        vec3.push_back(i.first);


    // 10.
    cout << "<контейнер #3>, полученный путём слияния <контейнер #1> и <контейнер #2>: " << endl;
    copy(vec3.begin(), vec3.end(), ostream_iterator<MyInt>(cout, " "));
    cout << '\n';

    // 11.
    cout << "Количество отрицательных элементов в <контейнер #3>: ";
    cout << count_if(vec3.begin(), vec3.end(),
        bind2nd(less<vector<MyInt>::value_type>(), 0)) << '\n';

    // 12.
    cout << "Проверить наличие в <контейнер #3> числа: ";
    cin >> i;
    bool found = binary_search(vec3.begin(), vec3.end(), i);
    cout << (found ? "Найдено" : "Не найдено") << '\n';

    return 0;
}