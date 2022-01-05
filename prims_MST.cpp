#include iostream
#include bitsstdc++.h
using namespace std;

#define V 5

//find vertex with min key value that is not yet included in MST
int minKey (int key[], bool mstSet[]){
    //initialize min value
    
    int min = INT_MAX, min_index;
    
    for(int v=0; v<V; v++){
        if(mstSet[v] == false && key[v] < min){
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V]) 
{ 
    cout<<"Edge \tWeight\n"; 
    for (int i = 1; i < V; i++) 
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
} 

void primMST(int graph[V][V]){
    //array to store MST
    int parent[V];
    
    //key values used to pick min edge weight in cut
    int key[V];
    
    bool mstSet[V]; //represent set of vertices included in mstSet
    
    //initialize keys as infinite and mstSet as false
    for(int i=0; i <V; i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    
    //pick first key
    key[0] = 0;
    parent[0] = -1; 
    
    for(int count = 0; count < V-1; count++){
        //pick the minimum vertex from the not included vertices
        int u = minKey(key, mstSet);
        
        //add the picked vertex to MST
        mstSet[u] = true;
        
        //update the key value and the parent index of adjacent vertices of the picked vertex
        for(int v=0; v<V; v++){
            //if non zero adjacent vertex, not included to MST
            if(mstSet[v] == false && graph[u][v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
        }
    }
    printMST(parent, graph);
}


int main() {
	int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 }}; 
                        
    primMST(graph); 

	return 0;
}