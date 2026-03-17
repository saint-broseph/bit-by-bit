/*
  You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) 
  such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
  Return the number of boomerangs.
*/

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int tot=0;

        for(int i=0; i<points.size(); i++)
        {
            unordered_map<int, int> distc;

            for(int j=0; j<points.size(); j++)
            {
                if(i==j) continue;

                int dx = points[i][0]-points[j][0];
                int dy = points[i][1]-points[j][1];

                int sqdist = dx*dx + dy*dy;

                distc[sqdist]++;
            }
            for(auto const& [distance, count] : distc)
                tot+=count*(count-1);
        }
        return tot;
    }
};
