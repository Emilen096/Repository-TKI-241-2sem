#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
     cout << "Print count of numbers: " << endl;
    int n;
    cin >> n;

    vector<double> nums(n);
    copy_n(istream_iterator<double>(cin), n, nums.begin());



    auto predicate = [index = 0](double) mutable
    {
        return (index++) % 2 == 0;
    };

        cout << "Numbers with even position: ";

    remove_copy_if(
        nums.begin(),
        nums.end(),
        ostream_iterator<double>(cout, " "),
        predicate
    );

    return 0;
}
