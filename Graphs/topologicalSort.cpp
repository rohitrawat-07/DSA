// cycle in directed graph 
 #include<iostream>
 #include<vector>
 #include<list>
 using namespace std;
class Graph{
    int V;
    list<int>* l;
    bool isUndir;
    public:
    Graph(int V , bool isUndir = true){
        this->V = V;
        l = new list<int> [V];
        this->isUndir = isUndir;
    }
   void addEdge(int v , int u){
    l[u].push_back(v);
    if(isUndir){
      l[v].push_back(u);
    }
   }
   void helper(int src , vector<bool>& vis , stack<int>& s){
      vis[src] = true;
      for(int v : l[src]){
        if(!vis[src]){
            helper(v , vis , s);
        }
      }

     s.push(src);
   }


   void topologicalSort(){
      vector<bool> vis(V , false);
      stack<int> s;
      for(int i = 0; i < V; i++){
        if(!vis[i]){
            helper(i , vis , s);
        }
      }
   
       // print;;;;;

       while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
       }
   }

};
int main() {
    int V = 6;
    Graph graph(V , false);
    graph.addEdge(2 , 3);
    graph.addEdge(3 , 1);
    graph.addEdge(4 ,0);
    graph.addEdge(4 , 1);
    graph.addEdge(5 , 0);
    graph.addEdge(5 , 2);
     graph.topologicalSort();
 }