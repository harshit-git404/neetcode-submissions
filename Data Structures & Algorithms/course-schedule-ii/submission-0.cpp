class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);

        for(auto p:prerequisites){
            int course=p[0];
            int prereq=p[1];
            graph[prereq].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        vector<int> order;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                order.push_back(i);
            }
        }

        while(!q.empty()){
            int course=q.front();
            q.pop();
            for(int next : graph[course]){
                indegree[next]--;
                if (indegree[next]==0){
                    q.push(next);
                    order.push_back(next);
                }
            }
        }
        if(order.size()==numCourses) return order;
        else return {};
    }
};