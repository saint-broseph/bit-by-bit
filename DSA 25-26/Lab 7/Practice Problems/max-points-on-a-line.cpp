/*
  Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
  */

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2) return n;

        int maxp=0;

        for(int i=0; i<n; i++)
        {
            unordered_map<string, int> slopec;
            int curmax=0;

            for(int j = i+1; j<n; j++)
            {
                int dx = points[j][0]-points[i][0];
                int dy = points[j][1]-points[i][1];

                int g = gcd(dx, dy);
                dx/=g;
                dy/=g;

                if(dx<0 || (dx==0 && dy<0))
                {
                    dx=-dx;
                    dy=-dy;
                }

                string slope = to_string(dx) + "_" + to_string(dy);
                slopec[slope]++;
                curmax = max(curmax, slopec[slope]);
            }
            maxp = max(maxp, curmax+1);
        }
        return maxp;
    }
};
