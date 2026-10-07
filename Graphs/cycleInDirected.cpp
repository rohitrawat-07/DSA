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
    l[v].push_back(u);
   }

   //
//    bool isCycleHelper(int u , int par ,vector<bool>& vis){     // 0(V+E)
//     vis[u] = true;
//     list<int> neighbour = l[u];
//     for(int v : neighbour){
//         if(!vis[v]){
//             if(isCycleHelper(v ,u, vis)){
//                 return true;
//             }
//         }else if(v != par){
//             return true;
//         }
//     }
//      return false;

//    }
//    bool isCycleUndirected(){
//       vector<bool> vis(V , false);
//       return isCycleHelper(0 , -1 , vis);
//    }
   bool cycleHelper(int src , vector<bool>& vis ,vector<bool>& recPath){
       vis[src] = true;
       recPath[src] = true;
       for(int v : l[src]){
        if(!vis[v]){
           if(cycleHelper(v , vis , recPath)){
            return true;
        }
        }else{
            if(recPath[v]){
            return true;
            }
          
        }
       }
       recPath[src] = false;
       return false;
   }
   bool isCycleDir() {
   vector<bool> vis(V , false);
   vector<bool> recPath(V , false);
   for(int i = 0; i < V; i++){
    if(!vis[i]){
        if(cycleHelper(i , vis , recPath)){
            return true;
        }
    }
   }
   return false;

   }

};
int main() {
    int V = 4;
    Graph graph(V);
    graph.addEdge(1 , 0);
    graph.addEdge(1 , 2);
    graph.addEdge(2 ,3);
    graph.addEdge(3 , 0);
      cout << graph.isCycleDir();
 }