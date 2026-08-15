#include<iostream>
#include<climits>
using namespace std;
#define V 5

int minDistance(int dist[],bool visited[]){
    int min=INT_MAX;
    int minIndex=-1;
    for(int v=0;v<V;v++){
        if(!visited[v]&& dist[v]<=min){
            min=dist[v];
            minIndex=v;
        }
    }
    return minIndex;
}
void printSolution(int dist[]){
    cout<<"Vertex \t Distance from source"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<"\t"<<dist[i]<<endl;
    }
}
void dijkstra(int graph[V][V],int src){
    int dist[V];
    bool visited[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        visited[i]=false;
    }
    dist[src]=0;
    for(int count=0;count<V-1;count++){
        int u=minDistance(dist,visited);
        visited[u]=true;
        for(int v=0;v<V;v++){
            if(!visited[v]&& graph[u][v]&& dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printSolution(dist);
}
int main() {
    int graph[V][V]={
    {0,2,4,0,0},
    {0,0,1,7,0},
    {0,0,0,3,0},
    {0,0,0,0,1},
    {0,0,0,0,0}
    };
    dijkstra(graph,0);
    return 0;
}