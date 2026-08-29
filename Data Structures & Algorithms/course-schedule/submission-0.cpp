class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);

        for(auto p:prerequisites){
            int course=p[0];
            int prereq=p[1];
            graph[prereq].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        //which can be taken without blockage
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        //for cyclic cases, like [1,2][2,1]... there are none that will be pushed here, so q empty
        //the cyclic ones will never enter the q, as they will always have prereq....
        while(!q.empty()){
            int course=q.front();
            q.pop();
            for(int next : graph[course]){
                indegree[next]--;
                if (indegree[next]==0) q.push(next);
            }
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]!=0) return false;
        }
        return true;
    }
};