#include <bits/stdc++.h>
using namespace std;

// Creating graph using adjacency list
class Graph{
private:
    unordered_map<int, list<int>> graph;

    // Breadth first search
    void bfs(int targetVertex, unordered_map<int, bool> &isVisited, vector<int> &ans){
        queue<int> que;
        que.push(targetVertex);
        isVisited[targetVertex] = true;

        while(!que.empty()){
            int frontNode = que.front();
            ans.push_back(frontNode);
            que.pop();
            for(auto i: graph[frontNode]){
                if(!isVisited[i]){
                    que.push(i);
                    isVisited[i] = true;
                }
            }
        }
    }

    // Depth first search
    void dfs(int targetVertex, unordered_map<int, bool> &isVisited, vector<int> &ans){
        isVisited[targetVertex] = true;
        ans.push_back(targetVertex);

        for(auto i: graph[targetVertex]){
            if(!isVisited[i]) dfs(i, isVisited, ans);
        }
    }

    // Topological sort using DFS traversal
    void sortDFS(int targetVertex, unordered_map<int, bool> &isVisited, stack<int> &st){
        isVisited[targetVertex] = true;

        for(auto i: graph[targetVertex]){
            if(!isVisited[i]){
                sortDFS(i, isVisited, st);
            }
        }
        st.push(targetVertex);
    }

    // Function to check if cycle is present or not in an undirected graph using BFS traversal
    bool cycleDtectionUGBFS(int targetVertex, unordered_map<int, bool> &isVisited){
        unordered_map <int, int> parent;
        parent[targetVertex] = -1;
        isVisited[targetVertex] = true;

        queue<int> que;
        que.push(targetVertex);

        while(!que.empty()){
            int frontNode = que.front();
            que.pop();

            for(auto i : graph[frontNode]){
                if(isVisited[i] && i != parent[frontNode]) return true;
                else if(!isVisited[i]){
                    que.push(i);
                    isVisited[i] = true;
                    parent[i] = frontNode;
                }
            }
        }
        return false;
    }

    // Function to check if cycle is present or not in an undirected graph using DFS traversal
    bool cycleDtectionUGDFS(int targetVertex, int parent ,unordered_map<int, bool> &isVisited){
        isVisited[targetVertex] = true;

        for(auto i : graph[targetVertex]){
            if(!isVisited[i]){
                bool ans = cycleDtectionUGDFS(i, targetVertex, isVisited);
                if(ans) return ans; 
            }
            else if(i != parent) return true;
        }
        return false;
    }

    // Function to check if cycle is present or not in a directed graph using DFS traversal
    bool cycleDetectionDGDFS(int targetVertex, unordered_map<int, bool> &isVisited, unordered_map<int, bool> &dfsVisited){
        isVisited[targetVertex] = true;
        dfsVisited[targetVertex] = true;

        for(auto i : graph[targetVertex]){
            if(!isVisited[i]){
                bool ans = cycleDetectionDGDFS(i, isVisited, dfsVisited);
                if(ans) return ans;
            }
            else if(dfsVisited[i]) return true;
        }
        dfsVisited[targetVertex] = false;
        return false;
    }

public:
    void insertion(int u, int v, bool isDirected){
        graph[u].push_back(v);
        if(!isDirected) graph[v].push_back(u);
    }

    void printGraph(){
        for(auto i: graph){
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << j << " ";
            }
            cout << endl;
        }
    }

    // Breadth first search algorithm for graphs
    vector<int> BFSTraversal(int targetVertex){
        unordered_map<int, bool> isVisited;
        vector<int> ans;

        bfs(targetVertex, isVisited, ans);

        for(auto i: graph){
            if(!isVisited[i.first]){
                bfs(i.first, isVisited, ans);
            }
        }
        return ans;
    }

    // Depth first search algorithm for graphs
    vector<int> DFSTraversal(int targetVertex){
        unordered_map<int, bool> isVisited;
        vector<int> ans;

        dfs(targetVertex, isVisited, ans);

        for(auto i: graph){
            if(!isVisited[i.first]){
                dfs(i.first, isVisited, ans);
            }
        }
        return ans;
    }

    // Topological Sort using DFS
    vector<int> topologicalSortDFS(int targetVertex){
        unordered_map<int, bool> isVisited;
        stack<int> st;
        vector<int> ans;

        sortDFS(targetVertex, isVisited, st);

        for(auto i: graph){
            if(!isVisited[i.first]){
                sortDFS(i.first, isVisited, st);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }

    // Topological sort using BFS (Kahns algoritham)
    vector<int> topologicalSortBFS(int targetVertex){
        unordered_map<int, int> indegree;
        
        for(auto i : graph){
            for(auto j : i.second){
                indegree[j]++;
            }
        }

        queue<int> que;
        que.push(targetVertex);

        vector<int> ans;
        while(!que.empty()){
            int front = que.front();
            que.pop();

            ans.push_back(front);

            for(auto i : graph[front]){
                indegree[i]--;
                if(indegree[i] == 0) que.push(i);
            }
        }
        return ans;
    }

    // Function to check if cycle is present or not in an undirected graph using BFS traversal
    bool isCyclicUGBFS(int targetVertex){
        unordered_map<int, bool> isVisited;

        bool ans = cycleDtectionUGBFS(targetVertex, isVisited);
        if(ans) return ans;

        for(auto i : graph){
            if(!isVisited[i.first]){
                bool ans = cycleDtectionUGBFS(i.first, isVisited);
                if(ans) return ans;
            }
        }
        return false;
    }

    // Function to check if cycle is present or not in an undirected graph using DFS traversal
    bool isCyclicUGDFS(int targetVertex){
        unordered_map<int, bool> isVisited;

        bool ans = cycleDtectionUGDFS(targetVertex, -1, isVisited);
        if(ans) return ans;

        for(auto i: graph){
            if(!isVisited[i.first]){
                bool ans = cycleDtectionUGDFS(i.first, -1, isVisited);
                if(ans) return ans;
            }
        }
        return false;
    }

    // Function to check if cycle is present or not in a directed graph using DFS traversal
    bool isCyclicDGDFS(int targetVertex){
        unordered_map<int, bool> isVisited;
        unordered_map<int, bool> dfsVisited;

        bool ans = cycleDetectionDGDFS(targetVertex, isVisited, dfsVisited);
        if(ans) return ans;

        for(auto i: graph){
            if(!isVisited[i.first]){
                bool ans = cycleDetectionDGDFS(i.first, isVisited, dfsVisited);
                if(ans) return ans;
            }
        }
        return false;
    }

    // Function to find shortest path from a source node to a destination node in Undirected unweighted graph using BFS Traversal
    vector<int> shortestPathUG(int sourceVertex, int destination){
        unordered_map<int, bool> isVisited;
        unordered_map<int, int> parent;
        
        queue<int> que;
        que.push(sourceVertex);
        parent[sourceVertex] = -1;
        isVisited[sourceVertex] = true;
        while(!que.empty()){
            int front = que.front();
            que.pop();

            for(auto i : graph[front]){
                if(!isVisited[i]){
                    que.push(i);
                    isVisited[i] = true;
                    parent[i] = front;
                }
            }
        }

        stack<int> st;
        st.push(destination);
        int nextNode = parent[destination];
        while(nextNode != -1){
            st.push(nextNode);
            nextNode = parent[nextNode];
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }

    
};

int main(){
    int numberOfEdges;
    cin >> numberOfEdges;

    Graph g1;
    for(int i=1; i<=numberOfEdges; i++){
        int u, v;
        cin >> u >> v;
        g1.insertion(u, v, 0);
    }

    g1.printGraph();
    cout << endl;

    vector<int> bfs = g1.BFSTraversal(1);
    for(auto i: bfs) cout << i << " ";
    cout << endl;
    vector<int> shortestPath = g1.shortestPathUG(1, 8);
    for(auto i: shortestPath) cout << i << " ";
    cout << endl;
}