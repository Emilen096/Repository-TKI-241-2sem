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
    int n;
    cout << "Enter the number of elements in vector V: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the elements of vector V: ";
    copy_n(istream_iterator<int>(cin), n, v.begin());

    sort(v.begin(), v.end(), less_abs());

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    return 0;
}
