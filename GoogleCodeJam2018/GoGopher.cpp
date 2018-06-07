#include <iostream> // includes cin to read from stdin and cout to write to stdout
#include <vector>

using namespace std; // since cin and cout are both in namespace std

constexpr int START_X = 5; // margin
constexpr int START_Y = 5; // margin

bool checkRange(const int x, const int y, int width, int height, const vector<vector<bool>> &grid)
{
    for (int i = x - 1, end_x = x + 1; i <= end_x; ++i)
    {
        for (int j = y - 1, end_y = y + 1; j <= end_y; ++j)
        {
            if (!grid[i][j])
            {
                return false; // this position can be shot
            }
        }
    }
    return true; // all digged
}

/*
 * Algorithm:
 * This is for small case.
 * The point walks around from (6, 6) to (4 + width, 4 + height)
 * and call Gophar if 3 x 3 block centered the point has the cell unprepared.
 */
int main()
{
    int t, a;
    cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i)
    {
        cin >> a;
        vector<vector<bool>> grid = vector<vector<bool>>(a + 10, vector<bool>(a + 10, false));
        int width = 5, height = 4;
        if (a == 200)
        {
            width = 20;
            height = 10;
        }
        int dest_x = START_X + width - 1;
        int dest_y = START_Y + height - 1;
        int x = START_X + 1;
        int y = START_Y + 1;
        for (int j = 0; j < 1000; ++j) // 1000 trial
        {
            while(checkRange(x, y, width, height, grid))
            {
                if (++x >= dest_x) // this row is done
                {
                    x = START_X + 1;
                    if (++y >= dest_y) // if y == dest_y, it can overgo
                        y = START_Y + 1;
                }
            }
            cout << x << " " << y << endl; // request x, y
            int dig_x, dig_y;
            cin >> dig_x >> dig_y; // result
            if (dig_x == 0 && dig_y == 0) // complete
                break;
            else if (dig_x == -1 && dig_y == -1) // error
                exit(-1);
            
            grid[dig_x][dig_y] = true;
            
            // walking
            if (++x == dest_x)
            {
                x = START_X + 1;
                if (++y == dest_y)
                    y = START_Y + 1;
            }
        }
    }
    return 0;
}