class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        initVariables(grid);
        traverse(grid, xStart, yStart, toVisit);
        return nValidPath;
    }

private:
    void initVariables(vector<vector<int>>& grid)
    {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                int n = grid[i][j];
                if (n == 1)
                {
                    xStart = i;
                    yStart = j;
                }
                else if (n == 0)
                    ++toVisit;
            }
        }
    }

    void move(vector<vector<int>>& grid, int x, int y, int toVisit)
    {
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
        {
            if (grid[x][y] == 2)
            {
                if (toVisit == 0)
                    ++nValidPath;
            }
            else if (grid[x][y] == 0)
            {
                grid[x][y] = 1;
                traverse(grid, x, y, toVisit - 1);
                grid[x][y] = 0;
            }
        }
    }

    void traverse(vector<vector<int>>& grid, int x, int y, int toVisit)
    {
        move(grid, x - 1, y, toVisit);
        move(grid, x + 1, y, toVisit);
        move(grid, x, y - 1, toVisit);
        move(grid, x, y + 1, toVisit);
    }

    int xStart = 0, yStart = 0, toVisit = 0, nValidPath = 0;
};