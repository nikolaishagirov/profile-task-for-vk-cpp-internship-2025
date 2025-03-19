

#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <map>
#include <vector>

class Graph {

private:

	std::map<int, std::vector<int>> adjList;

public:

	void addEdge(int v, int w);
    
	/* get the shortest distances from a vertex with startVertexId
	to all other vertices using Breadth First Search (BFS) */
	std::vector<int> BFS(int startVertexId);
};



#endif /* GRAPH_HPP_ */
