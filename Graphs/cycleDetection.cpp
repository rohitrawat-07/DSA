// cycle detection in undirected graph
 #include<iostream>
 #include<vector>
 #include<list>
 using namespace std;
class Graph{
    int V;
    list<int>* l;
    public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }
   void addEdge(int v , int u){
    l[u].push_back(v);
    l[v].push_back(u);
   }
   bool isCycleHelper(int u , int par ,vector<bool>& vis){     // 0(V+E)
    vis[u] = true;
    list<int> neighbour = l[u];
    for(int v : neighbour){
        if(!vis[v]){
            if(isCycleHelper(v ,u, vis)){
                return true;
            }
        }else if(v != par){
            return true;
        }
    }
     return false;

   }
   bool isCycleUndirected(){
      vector<bool> vis(V , false);
      return isCycleHelper(0 , -1 , vis);
   }

};
int main() {
    int V = 5;
    Graph graph(V);
    graph.addEdge(0 , 1);
    graph.addEdge(0 , 2);
    graph.addEdge(0 , 3);
    graph.addEdge(1, 2);
    graph.addEdge(3 , 4);
    cout << graph.isCycleUndirected();
     return 0;
 }