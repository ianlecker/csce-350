#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    int n;
    int r;
    cout << "Enter the number of lockers" << endl;
    cin >> n;
    cout << "Enter the number of passes" << endl;
    cin >> r;

    vector<bool> lockers(n + 1, false); // add one to account for starting at locker 1

    for (int i = 1; i <= r; i++) {
        for (int j = i; j <= n; j += i){ // add pass i to the iterator
            lockers[j] = !lockers[j];
        }
    }

    int openCount = 0;

    for (int i = 1; i <= n; ++i) {
        if (lockers[i]) {
            cout << "locker " << i << " open" << endl;
            ++openCount;
        } else {
            cout << "locker" << i << " closed" << endl;
        }
    }

    cout << "open lockers: " << openCount << endl;
    cout << "closed lockers: " << (n - openCount) << endl;

    return 0;
}