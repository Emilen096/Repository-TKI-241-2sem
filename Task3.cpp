#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int n1, n2;
    cout << "Enter the number of elements in vector V1: ";
    cin >> n1;

    vector<int> v1(n1);
    cout << "Enter the elements of vector V1: ";
    copy_n(istream_iterator<int>(cin), n1, v1.begin());

    cout << "Enter the number of elements in vector V2: ";
    cin >> n2;

    vector<int> v2(n2);
    cout << "Enter the elements of vector V2: ";
    copy_n(istream_iterator<int>(cin), n2, v2.begin());

    map<int, vector<int>> m;
    for (vector<int>::const_iterator it = v2.begin(); it != v2.end(); ++it)
        m[abs(*it % 10)].push_back(*it);

    vector<pair<int, int>> v;
    for (vector<int>::const_iterator it1 = v1.begin(); it1 != v1.end(); ++it1)
    {
        map<int, vector<int>>::const_iterator it = m.find(abs(*it1 % 10));
        if (it == m.end())
            continue;

        for (vector<int>::const_iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            v.push_back(make_pair(*it1, *it2));
    }

    cout << v.size() << '\n';
    for (vector<pair<int, int>>::const_iterator it = v.begin(); it != v.end(); ++it)
        cout << it->first << ' ' << it->second << '\n';

    return 0;
}
