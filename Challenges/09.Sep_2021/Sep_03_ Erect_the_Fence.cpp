class Solution
{
public:
    class Point
    {
    public:
        int x;
        int y;

        bool operator < (Point(&P))
        {
            if (P.x == x)
                return y < P.y;
            else
                return x < P.x;
        }
        bool operator == (Point(&P))
        {
            return (x == P.x and y == P.y);
        }
    };
    bool cw(Point a, Point b, Point c)
    {
        return (((b.y - a.y) * (c.x - b.x)) - ((c.y - b.y) * (b.x - a.x))) > 0;
    }
    bool acw(Point a, Point b, Point c)
    {
        return (((b.y - a.y) * (c.x - b.x)) - ((c.y - b.y) * (b.x - a.x))) < 0;
    }
    bool col(Point a, Point b, Point c)
    {
        return (((b.y - a.y) * (c.x - b.x)) - ((c.y - b.y) * (b.x - a.x))) == 0;
    }
    void convex_hull(vector<Point>& p)
    {
        if (p.size() <= 2) return;
        int n = p.size();
        sort(p.begin(), p.end());
        Point p1 = p[0], p2 = p[n - 1];
        vector <Point> up, down;
        up.push_back(p1);
        down.push_back(p1);
        for (int i = 1; i < n; i++)
        {
            if (i == n - 1 or (!acw(p1, p[i], p2)))
            {
                while (up.size() >= 2 and (acw(up[up.size() - 2], up[up.size() - 1], p[i])))
                {
                    up.pop_back();
                }
                up.push_back(p[i]);
            }
            if (i == n - 1 or (!cw(p1, p[i], p2)))
            {
                while (down.size() >= 2 and (cw(down[down.size() - 2], down[down.size() - 1], p[i])))
                {
                    down.pop_back();
                }
                down.push_back(p[i]);
            }
        }
        p.clear();
        for (int i = 0; i < up.size(); i++)
            p.push_back(up[i]);
        for (int i = 0; i < down.size(); i++)
            p.push_back(down[i]);
        sort(p.begin(), p.end());
        p.resize(unique(p.begin(), p.end()) - p.begin());
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees)
    {
        vector<Point> p;
        for (int i = 0;i < trees.size();i++)
        {
            Point temp;
            temp.x = trees[i][0];
            temp.y = trees[i][1];
            p.push_back(temp);
        }
        convex_hull(p);
        vector<vector<int> > ans;
        for (int i = 0;i < p.size();i++)
        {
            ans.push_back({ p[i].x, p[i].y });
        }
        return ans;
    }
};

// ------------------ 28ms Submission ----------------------

// class Solution {
// public:

//     struct point {
//         int x, y;

//         bool operator < (point& O) {
//             if (O.x == x) return y < O.y;
//             else return x < O.x;
//         }
//         bool operator == (point& O) {
//             return (x == O.x && y == O.y);
//         }
//     };


//     bool cw(point a, point b, point c) {  // clock wise

//         return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
//     }

//     bool ccw(point a, point b, point c) {   // counter clock wise

//         return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
//     }

//     void convec_hull(vector<point>& p) {

//         if (p.size() <= 2) return;

//         sort(p.begin(), p.end());

//         int i, n = p.size();

//         point p1 = p[0], p2 = p[n - 1];
//         // p1 is bottom left p and p2 is top right point
//         vector<point> up, down;
//         up.push_back(p1);
//         down.push_back(p1);

//         for (i = 1; i < n; i++) {
//             // now check whether my current p is in lower half
//             // or upper half

//             if (i == n - 1 || !ccw(p1, p[i], p2)) { // check if not counter clock wise (it consider both clock wise and collinear pts)
//                 while (up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], p[i])) {
//                     up.pop_back();
//                 }
//                 up.push_back(p[i]);
//             }
//             if (i == n - 1 || !cw(p1, p[i], p2)) { // check if not clock wise
//                 while (down.size() >= 2 && cw(down[down.size() - 2], down[down.size() - 1], p[i])) {
//                     down.pop_back();
//                 }
//                 down.push_back(p[i]);
//             }
//         }

//         p.clear();
//         for (i = 0; i < up.size(); i++) {
//             p.push_back(up[i]);
//         }

//         for (i = 0; i < down.size(); i++) {
//             p.push_back(down[i]);
//         }

//         sort(p.begin(), p.end());
//         p.resize(unique(p.begin(), p.end()) - p.begin());  // take only unique values
//     }
//     vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
//         int n = trees.size();
//         vector<point> p(n);

//         for (int i = 0; i < trees.size(); i++) {
//             p[i].x = trees[i][0];
//             p[i].y = trees[i][1];
//         }

//         convec_hull(p);
//         vector<vector<int>> ans;

//         for (auto j : p) {
//             ans.push_back({ j.x,j.y });
//         }
//         return ans;
//     }
// };

// ---------------------------------------------------------

// ------------------19100KB Submission --------------------

// class Solution {
//     static bool cmpTrees(const vector<int>& lhs, const vector<int>& rhs) {
//         return (lhs[0] < rhs[0]) or ((lhs[0] == rhs[0]) and (lhs[1] < rhs[1]));
//     }

//     static int xProd(const vector<int>& p0, const vector<int>& p1, const vector<int>& p2) {
//         return (p1[0] - p0[0]) * (p2[1] - p0[1]) - (p1[1] - p0[1]) * (p2[0] - p0[0]);
//     }
// public:
//     vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
//         const int n = trees.size();
//         if (n <= 3) {
//             return move(trees);
//         }
//         sort(trees.begin(), trees.end(), cmpTrees);
//         int j = 1;
//         for (int k = j + 1, e = j; k != n; ++k) {
//             while ((j >= e) and (xProd(trees[j - 1], trees[j], trees[k]) < 0)) {
//                 --j;
//             }
//             ++j;
//             if (j != k) {
//                 trees[j].swap(trees[k]);
//             }
//         }
//         ++j;
//         if (j == n) {
//             return move(trees);
//         }
//         sort(trees.rbegin(), trees.rend() - j, cmpTrees);
//         const int e = j;
//         for (int k = j + 1; k < n; ++k) {
//             while ((j >= e) and (xProd(trees[j - 1], trees[j], trees[k]) < 0)) {
//                 --j;
//             }
//             ++j;
//             if (j != k) {
//                 trees[j].swap(trees[k]);
//             }
//         }
//         while ((j >= e) and (xProd(trees[j - 1], trees[j], trees[0]) < 0)) {
//             --j;
//         }
//         trees.resize(j + 1);
//         return move(trees);
//     }
// };

// ---------------------------------------------------------
