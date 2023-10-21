class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        set<pair<int, int>>st;
        vector<int>dist(v, 1e9);
        dist[s] = 0;
        st.insert({0, s});
        while(!st.empty()){
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);
            for(auto i : adj[node]){
                int edgeWeight = i[1];
                int adjNode = i[0];
                if(dis+edgeWeight < dist[adjNode]){
                    if(dist[adjNode] == 1e9)
                        st.erase({dist[adjNode], adjNode});
                    dist[adjNode] = dis+edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
