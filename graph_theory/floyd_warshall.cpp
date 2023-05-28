    void floyd_warshall(int n)
    {
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(i == j)
                    {
                        min_distance[i][j] = 0;
                        continue;
                    }
                    if(min_distance[i][k] == INT_MAX || min_distance[k][j] == INT_MAX)
                        continue;
                    if(min_distance[i][j] > min_distance[i][k] + min_distance[k][j])
                        min_distance[i][j] = min_distance[i][k] + min_distance[k][j];
                }
            }
        }
    }
