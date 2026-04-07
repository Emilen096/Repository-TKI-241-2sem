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

    vector<string> lines;
    string line;
    while (getline(cin, line))
        if (!line.empty())
            lines.push_back(line);

    string line1;
    string line2;
    if (!lines.empty())
        line1 = lines[0];

    for (vector<string>::size_type i = 1; i < lines.size(); ++i)
    {
        if (!line2.empty())
            line2 += ' ';
        line2 += lines[i];
    }

    istringstream in1(line1);
    vector<int> v1{istream_iterator<int>(in1), istream_iterator<int>()};

    istringstream in2(line2);
    vector<int> v2{istream_iterator<int>(in2), istream_iterator<int>()};

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
