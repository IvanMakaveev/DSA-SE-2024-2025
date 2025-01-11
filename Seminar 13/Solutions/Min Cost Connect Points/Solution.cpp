class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> vis(points.size(), 0);

        pq.push({0,0});
        int sum = 0;

        while(!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(!vis[node])
            {
                vis[node] = true;
                sum += wt;
                for(int adjNode = 0; adjNode < points.size(); adjNode++)
                {
                    if(!vis[adjNode])
                    {
                        int dist = abs(points[adjNode][1] - points[node][1])
                        + abs(points[adjNode][0] - points[node][0]);

                        pq.push({dist, adjNode});
                    }
                }
            }
        }

        return sum;

    }
};
