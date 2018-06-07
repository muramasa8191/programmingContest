#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

int damageCheck(string str)
{
    int damage = 0;
    int atk = 1;
    for (char c : str)
    {
        if (c == 'S')
            damage += atk;
        else
            atk *= 2;
    }
    
    return damage;
}

int swapTest(int defence, string str)
{
    int idx = str.size()-1, swap_cnt = 0;
    while(idx > 0)
    {
        // change biggest charge and shot
        // target to reduce damage
        if (str[idx] == 'S' && str[idx-1] == 'C')
        {
            ++swap_cnt;
            str[idx] = 'C';
            str[idx-1] = 'S';
            if (damageCheck(str) <= defence) // acceptable
            {
                break;
            }
            else
                idx = str.size(); // start over
        }
        --idx;
    }
    return swap_cnt;
}

/*
 * Algorithm:
 * check original string and print 0 if the condition is already satisfied
 * or IMPOSSBLE if the count of S exceed D because minimum damage is # of S x 1.
 * Then, start swapping. Swap rightmost CS pair because it reduces damage the most.
 * Repeatedly, it swaps and checks whether the damage is acceptable or not.
 * Once it mees the condition, print the number of swap. It should be there
 * because S+C+ must satisfy in the worst case.
 */
int main()
{
    int t, d;
    string str;
    cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i)
    {
        cin >> d;
        cin >> str; // read n and then m.
        cout << "Case #" << i << ": ";
        
        // parse string
        int s_num = 0; // the count of the shot
        int c_num = 0; // the count of charge
        
        int atk = 1; // attack point
        int damage = 0;
        for (int j = 0; j < str.size(); ++j)
        {
            if (str[j] == 'S')
            {
                ++s_num;
                damage += atk;
            }
            else // guarantee char is one of S or C
            {
                ++c_num;
                atk *= 2;
            }
        }
        if (damage <= d)
        {
            cout << 0 << endl; // already satisfied the condition
            continue;
        }
        else if (d < s_num) // 1 * S > D -> impossible
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        int swapCnt = swapTest(d, str);
        cout << swapCnt << endl;
    }
    return 0;
}