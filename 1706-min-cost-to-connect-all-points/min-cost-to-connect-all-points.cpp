class Solution {
public:
    typedef pair<int, int> P;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<P>> adj(n);

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int wt = abs(x2 - x1) + abs(y2 - y1);

                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }

        vector<bool> vis(n, false);

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        int cost = 0;

        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(vis[node]){
                continue;
            }

            vis[node] = true;
            cost += wt;

            for(auto& ngbr : adj[node]){
                int ngbrNode = ngbr.first;
                int ngbrWt = ngbr.second;

                if(vis[ngbrNode]){
                    continue;
                }

                pq.push({ngbrWt, ngbrNode});
            }
        }
        return cost;
    }
};