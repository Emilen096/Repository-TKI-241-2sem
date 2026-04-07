#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    cout << "Enter the numbers: " << endl;
    vector<double> nums{istream_iterator<double>(cin), istream_iterator<double>()};

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
