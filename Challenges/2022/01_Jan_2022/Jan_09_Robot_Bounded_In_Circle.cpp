class Solution {
public:

    pair<int, int> move(int x, int y, string& path)
    {
        int dx[4] = { 0,1,0,-1 };
        int dy[4] = { 1,0,-1,0 };
        int curr = 0;
        int i = 0;
        while (i < path.size())
        {
            if (path[i] == 'G')
            {
                x += dx[curr];
                y += dy[curr];
            }
            else if (path[i] == 'R')
            {
                curr = (curr + 1) % 4;
            }
            else
            {
                if (curr == 0)curr = 3;
                else curr--;
            }
            i++;
        }
        pair<int, int> ret = { x,y };
        return ret;
    }
    bool isRobotBounded(string p) {
        string path = p;
        path += path;
        path += path;
        pair<int, int> last = move(0, 0, path);
        if (last.first == 0 && last.second == 0)return true;
        return false;
    }
};