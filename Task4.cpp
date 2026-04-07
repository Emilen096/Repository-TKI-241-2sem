#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

struct less_abs : function<bool(int, int)>
{
    bool operator()(int a, int b) const
    {
        return abs(a) < abs(b);
    }
};

int main()
{
    cout << "Enter the elements of vector V: ";
    vector<int> v{istream_iterator<int>(cin), istream_iterator<int>()};

    sort(v.begin(), v.end(), less_abs());

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    return 0;
}
