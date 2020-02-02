#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

//Determining if a graph is bipartite
//Equivalent to check that it is 2-colorable
//We'll use Depth First Search

//Edge Class aka undirected arrow
struct Arrow{
    int source;
    int target;
};

//Graph class

class Graph{
    int n;//number of nodes
    vector<vector<int>> AdjMatrix;
    //Constructor for Graph given the edges and number of nodes
    Graph(vector<Arrow> &arrows, int size){
        n=size;
        AdjMatrix.resize(size);
        for(int i=0;i<arrows.size();i++)
        {
            AdjMatrix[arrows[i].source].push_back(arrows[i].target);
            AdjMatrix[arrows[i].target].push_back(arrows[i].source);
        }
    }

    //Bool values in color track the coloring of nodes
    bool CheckBipartite(int start, vector<bool>& visited, vector<bool>& color){
        for(int i: AdjMatrix[start]){
            if (visited[start]==false){
                visited[start]=true;
                color[i]=!color[start];
                if (!CheckBipartite(start,visited,color))
                    return false;
            }

            else if(color[i]==color[start])
                return false;
        }
        return true; //2-colorable
    }

};
