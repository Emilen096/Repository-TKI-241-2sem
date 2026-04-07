#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
    deque<int> d{istream_iterator<int>(cin), istream_iterator<int>()};
    const deque<int>::size_type n = d.size();

    auto mid = next(d.begin(), n / 2);

    for (auto r = decltype(d.rbegin())(mid); r != d.rend(); ++r)
        r = decltype(r)(d.erase(--r.base()));

    copy(d.begin(), d.end(), ostream_iterator<int>(cout, " "));

    return 0;
}
