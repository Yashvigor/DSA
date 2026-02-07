class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int done = 0;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            done++;

            for (int i = 0; i < adj[cur].size(); i++) {
                int next = adj[cur][i];
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        return done == numCourses;
    }
};
