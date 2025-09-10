#include <vector>
#include <iostream>
#include <string>
using namespace std;

void solve(int row, int col, string path, vector<string> &ans, vector<vector<int>> &maze)
{
    int n = maze.size();

    if ((row == maze.size() - 1 && col == maze.size() - 1) && maze[row][col] == 1)
    {
        ans.push_back(path);
        return;
    }

    maze[row][col] = -1;

    // Since problems asks solution in lexical order we are
    // executing the direction in lexical order D,L,R,U

    // Moving Down
    if (row + 1 < n && maze[row + 1][col] == 1)
    {
        solve(row + 1, col, path + "D", ans, maze);
    }

    // Left
    if (col - 1 >= 0 && maze[row][col - 1] == 1)
    {
        solve(row, col - 1, path + "L", ans, maze);
    }

    // Moving Right
    if (col + 1 < n && maze[row][col + 1] == 1)
    {
        solve(row, col + 1, path + "R", ans, maze);
    }

    // Moving Up
    if (row - 1 >= 0 && maze[row - 1][col] == 1)
    {
        solve(row - 1, col, path + "U", ans, maze);
    }

    maze[row][col] = 1;

    return;
}

int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1},
    };
    vector<string> ans;
    string s;

    solve(0, 0, s, ans, maze);

    for (string path : ans)
    {
        cout << path << endl;
    }

    return 0;
}