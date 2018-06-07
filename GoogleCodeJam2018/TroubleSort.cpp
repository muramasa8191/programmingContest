#include <iostream> // includes cin to read from stdin and cout to write to stdout
#include <vector>
#include <algorithm>
using namespace std; // since cin and cout are both in namespace std,

/*
 * Algorithm:
 * TroubleSort sorts two sets of numbers: numbers with even-numbered index and
 * odd-numbered index. So we can use two vectors and sort them respectively.
 * Check one by one from the beginning to the end.
 */
int main()
{
    int t, n;
    cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i)
    {
        cin >> n; // the # of integers
        
        vector<long> odds; // vec for # with odd-numbered
        vector<long> evens; // vec for # with even-numbered
        for (int j = 0; j < n; ++j)
        {
            long l;
            cin >> l;
            if (j % 2 == 0)
                evens.push_back(l);
            else
                odds.push_back(l);
        }
        sort(odds.begin(), odds.end()); // O(n/2 log n/2)
        sort(evens.begin(), evens.end()); // O(n/2 log n/2)

        int j = 0;
        for (; j < n - 1; ++j) // O(n)
        {
            long curr = j % 2 == 0 ? evens[j/2] : odds[j/2];
            ssize_t nextIdx = (j + 1);
            long next = nextIdx % 2 == 0 ? evens[nextIdx/2] : odds[nextIdx/2];
            if (curr > next)
                break;
        }
        cout << "Case #" << i << ": ";
        if (j == n - 1)
            cout << "OK";
        else
            cout << j;
        cout << endl;
    }
    return 0;
}