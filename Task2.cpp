#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
    int n;
    cin >> n;

    deque<int> d(n);
    copy_n(istream_iterator<int>(cin), n, d.begin());

    auto mid = next(d.begin(), n / 2);

    for (auto r = decltype(d.rbegin())(mid); r != d.rend(); ++r)
        r = decltype(r)(d.erase(--r.base()));

    copy(d.begin(), d.end(), ostream_iterator<int>(cout, " "));

    return 0;
}
