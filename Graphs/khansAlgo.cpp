#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int>* l;
    public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }
     void addEdge(int u , int v){
        l[u].push_back(v);
     }
     void calc(vector<int>& indegree){
        
        for(int j = 0; j < V; j++){
            for(int v : l[j]){
                indegree[v]++;
            }
        }
     }
     void kahns(){
        vector<int> indegree(V , 0);
        queue<int> q;
        calc(indegree);
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
             q.pop();
             cout << curr << " ";
            for(int v : l[curr]){
                indegree[v]--;

               if(indegree[v] == 0){
                q.push(v);
            }
            }
        }
        cout << endl;
     }
};

int main() {
    Graph graph(6);
    graph.addEdge(2 , 3);
    graph.addEdge(3 , 1);
    graph.addEdge(4 ,0);
    graph.addEdge(4 , 1);
    graph.addEdge(5 , 0);
    graph.addEdge(5 , 2);
    cout << "Starting..." << endl;

     graph.kahns();

    return 0;
}


