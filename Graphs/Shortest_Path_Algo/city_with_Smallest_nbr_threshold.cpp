 int dijkstra(int src ,int threshold, int n , vector<vector<int>>adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        vector<int>dist(n,1e9);
        
        dist[src]= 0;
        pq.push({0,src});
        
        while(!pq.empty())
        {
            auto it = pq.top(); pq.pop();
            int dis = it.first;
            int node = it.second;
            
            for(auto nbr : adj[node])
            {
                int v = nbr[0];
                int wt = nbr[1];
                if(dist[v] > dis + wt)
                {
                    dist[v] = dis + wt;
                    pq.push({dist[v],v});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(dist[i] <= threshold)
            {
                cnt++;
            }
        }
        return cnt;
    }
  
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold)
    {
        // convert into adj list
        vector<vector<int>>adj[n];
        for(int i=0;i<m;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        
        }
    
        int count = n+1;
        int city = -1;
        
        for(int node=0;node<n;node++)
        {
            // do dijkstra for each node
            // find cities which are within threshold
            
            int nbrCities = dijkstra(node,distanceThreshold,n,adj);
            
            if(nbrCities <= count)
            {
                city = node;
                count = nbrCities;
            }
        }
        return city;
    }


///   floyd warshall
int findCity(int n, int m, vector<vector<int>>& edges,
	             int distanceThreshold) {
		vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
		for (auto it : edges) {
			dist[it[0]][it[1]] = it[2];
			dist[it[1]][it[0]] = it[2];
		}
		for (int i = 0; i < n; i++) dist[i][i] = 0;
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
						continue;
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		int cntCity = n;
		int cityNo = -1;
		for (int city = 0; city < n; city++) {
			int cnt = 0;
			for (int adjCity = 0; adjCity < n; adjCity++) {
				if (dist[city][adjCity] <= distanceThreshold)
					cnt++;
			}

			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = city;
			}
		}
		return cityNo;

	}
