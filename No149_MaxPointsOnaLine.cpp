// 149. Max Points on a Line

// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

// 我的思路：首先将所有点俩俩组合，计算出所有直线的斜率，之后斜率相同最多的也就是要返回的结果
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if(n == 0)
            return 0;
        // sort(points.begin(), points.end(), cmp_sort);
        // auto it = unique(points.begin(), points.end(), cmp);
        // points.resize(distance(points.begin(), it));
        
        if(points.size() < 2){
            return points.size();
        }
        // n = points.size();
        vector<int> comb;
        vector<vector<int> > path;
        combination_util(n, 0, 0, comb, path);
        
        // Now path contains all combination of points
        map<pair<int, int>, map<double,set<int> > > slopes;
        map<int, set<int> > vertical;
        for(auto item : path){
            int x1 = points[item[0]].x;
            int x2 = points[item[1]].x;
            int y1 = points[item[0]].y;
            int y2 = points[item[1]].y;
            int X = x1 - x2;
            int Y = y1 - y2;
            int g = gcd(X,Y);
            // cout << g<< endl;
            if(g != 0){ // Because it might occur X and Y are both 0
                X = X/g;
                Y = Y/g;
            }
            
            if(X < 0){  // Keep nominator pos
                X = X*-1;
                Y = Y*-1;
            }
            if(X == 0){ // 这里考虑垂直的直线，没有斜率，但是也要对这些直线做出区分
                vertical[points[item[0]].x].insert(item[0]);
                vertical[points[item[0]].x].insert(item[1]);
            }
            else{
                double b = ((x2*y1)-(x1*y2)) / (x2-x1);
                slopes[make_pair(X,Y)][b].insert(item[0]);
                slopes[make_pair(X,Y)][b].insert(item[1]);
            }
            
        }

        // Find the max num
        int res = INT_MIN;
        for(auto item : slopes){
            for(auto i : item.second)
                res = max(res, (int)i.second.size());
        }
        for(auto item : vertical){
            res = max(res, (int)item.second.size());
        }
        return res;

    }
    static bool cmp_sort(Point a, Point b){
        if(a.x < 0){
            a.x = a.x * -1;
            a.y = a.y * -1;
        }
        if(b.x < 0){
            b.x *= -1;
            b.y *= -1;
        }
        return (a.x < b.x) && (a.y < b.y);
    }
    static bool cmp(Point a, Point b){
        return (a.x == b.x) && (a.y == b.y);
    }
    void combination_util(int n, int num, int index, vector<int>& comb, vector<vector<int> >& path){
        if(num == 2){
            path.push_back(comb);
            return;
        }

        for(int i=index; i<n; i++){
            comb.push_back(i);
            combination_util(n, num+1, i+1, comb, path);
            comb.pop_back();
        }
        return;
    }

    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }

};