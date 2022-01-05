#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <stack>

#define V 9

//find vertex with min key value that is not yet included in MST
int minDistance (int distance[], bool sptSet[]){
    //initialize min value
    
    // Initialize min value 
    int min = INT_MAX, min_index; 

    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && distance[v] < min) 
            min = distance[v], min_index = v; 

    return min_index; 
}

void printSolution(int distance[]) 
{ 
    cout<<"Vertex \t Distance from Source\n"; 
    for (int i = 0; i < V; i++) 
        cout << i << " \t\t" << distance[i] <<" \n"; 
} 

void printSPTs(int path[], int src){
    int v;
    for (int target = 0; target < V; target++){
        
        cout << src << " to " << target << " ---> ";
        stack <int> shortestPath;
        
        if(target!=src) {
    		shortestPath.push(target);
    		v=target;
    
    		while(v!=src){
    			v=path[v];
    			shortestPath.push(v);
    		}
    	}else{
    	    shortestPath.push(target);
    	}
    	while(!shortestPath.empty()){
    	    cout << shortestPath.top() <<" ";
    	    shortestPath.pop();
    	}
    	cout << endl;
    }   
}

void dijkstra(int graph[V][V], int src){
    
    //array to store shortest distances from source
    int dist[V];
    
    bool sptSet[V]; //represent set of vertices included in mstSet
    
    int path[V];
    
    //initialize all distances as infinite and sptSet as false
    for(int i=0; i <V; i++){
        dist[i] = INT_MAX;
        sptSet[i] = false;
        path[i]=src;
    }
    
    //pick source firstly
    dist[src] = 0;
    
    //Find shortest path for all vertices
    for(int count = 0; count < V-1; count++){
        //pick the minimum distance vertex from the not included vertices
        int u = minDistance(dist, sptSet);
        
        //add the picked vertex to SPT
        sptSet[u] = true;
        
        //update the distance value and the parent index of adjacent vertices of the picked vertex
        for(int v=0; v<V; v++){
            //if non zero adjacent vertex, not included to MST
            if(graph[u][v] && sptSet[v] == false &&  dist[u]!=INT_MAX && graph[u][v] + dist[u] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
                path[v]=u;
            }
        }
    }
    printSolution(dist);
    
    printSPTs(path, src);

}


int main() {
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph,0);

	return 0;
}