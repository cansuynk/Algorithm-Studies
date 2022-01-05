#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class DSU { //Union-Find Detect cycle algorithm
    int *parent;
    int *rank;
    
    public:
    DSU(int n){ //takes a size
        parent = new int[n];
        rank = new int[n];
        
        //initializes arrays
        for (int i = 0; i < n; i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    
    int find(int i){
        if (parent[i] == -1){
            return i;
        }
        
        return parent[i] = find(parent[i]);
    }
    
    void unionn (int x, int y){
        int s1 = find(x);
        int s2 = find(y);
        
        if (s1 != s2){
            if (rank[s1] < rank [s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }else{
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph {
    private:
        vector<vector<int>> edges;
        int V;
    
    public:
    Graph(int V){
        this->V = V;
    }
    void addEdge(int x, int y, int w){
        this->edges.push_back({w, x, y});
    }
    
    int kruskalsMST(){
        //1. sort edges
        sort(edges.begin(), edges.end());
        
        //2. pick the small edge that performing a minimum spanning tree but not a cycle
        //need a detection cycle algorithm
        DSU s(V);
        int ans = 0;
        
        for (auto edge : edges){
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            
            //discard the edge if it does form a cycle
            if(s.find(x) != s.find(y)){
                s.unionn(x,y);
                ans += w;
            }
        }
        return ans;
    }
};


int main() {
	Graph g(4);
	
	g.addEdge(0, 1, 1);
	g.addEdge(1, 3, 3);
    g.addEdge(3, 2, 4);
    g.addEdge(2, 0, 2);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 2);
    
    cout << g.kruskalsMST() << endl;
	
	return 0;
}