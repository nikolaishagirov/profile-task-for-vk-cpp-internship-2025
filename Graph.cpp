#include <map>
#include <queue>
#include <vector>
#include <iostream>

#include "Graph.hpp"

void Graph::addEdge(int v, int w) {
	adjList[v].push_back(w);
	adjList[w].push_back(v);
}

std::vector<int> Graph::BFS(int startVertexId) {
	std::map<int,bool> visited;
	std::queue<int> queue;
	std::vector<int> distFromStartVertex(adjList.size()==0? 1: adjList.size());
	int curDistance = 0;
	visited[startVertexId] = true;
	distFromStartVertex[startVertexId] = curDistance;
	queue.push(startVertexId);
	while(!queue.empty()) {
		int vertexId = queue.front();
		//std::cout<<"Visited vertex with id = "<<vertexId<<"\n";
		queue.pop();
		curDistance++;
		for(auto vId: adjList[vertexId]) {
			if(!visited[vId]) {
				queue.push(vId);
				visited[vId] = true;
				distFromStartVertex[vId] = curDistance;
			}
		}
	}
	return distFromStartVertex;
}




