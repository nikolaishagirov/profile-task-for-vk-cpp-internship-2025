#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

#include "Graph.hpp"

int main() {
    const char* filename = "graph.txt";
    std::ifstream inputFile(filename);
    if(!inputFile.is_open()) {
        std::cerr<<"Cannot read file "<<filename<<"\n";
        exit(-1);
    }
    std::string line;
    Graph graph;
    int nVertices, nEdges, startVertexId;
    int lineNumber = 0;

    try {

        // read a number of vertices

        std::getline(inputFile, line);
        lineNumber++;
        nVertices = std::stoi(line);
        if(nVertices<=0) {
            std::cerr<<"A number of vertices in a graph must be positive"<<"\n";
            throw lineNumber;
        }

        int minEdgesCount = (nVertices==1)? 0:1;
        int maxEdgesCount = nVertices*(nVertices-1)/2;

        // read a number of edges

        std::getline(inputFile, line);
        lineNumber++;
        nEdges = std::stoi(line);
        if(nEdges<minEdgesCount || nEdges>maxEdgesCount) {
            std::cerr<<"Invalid number of edges: "
                <<"the number of edges must be in range"
                <<" ["<<minEdgesCount<<", "<<maxEdgesCount
                <<"]"<<" when a total number of vertices "
                <<"is equal "<<nVertices<<"\n";
            throw lineNumber;
        }

        // read a list of edges
        for(int i=0; i<nEdges; i++) {
            std::getline(inputFile,line);
            lineNumber++;
            auto spacePos = line.find(' ');
            if(spacePos==std::string::npos) {
                throw lineNumber;
            }
            int v = std::stoi(line.substr(0,spacePos));
            int w = std::stoi(line.substr(spacePos+1, line.length()));
            if(v<0 || v>=nVertices || w<0 || w>=nVertices || v==w) {
                std::cerr<<"Ids of vertices forming an edge "
                    <<"must be different, non-negative and less than "
                    <<"a total number of vertices in a graph"<<"\n";
                throw lineNumber;
            }
            graph.addEdge(v,w);
        }

        // read start vertex id

        std::getline(inputFile, line);
        lineNumber++;
        startVertexId = std::stoi(line);
        if(startVertexId<0 || startVertexId>=nVertices) {
            std::cerr<<"Invalid id of start vertex. "
                <<"An id of start vertex must be non-negative "
                <<"and less than a total number of vertices in a graph"
                <<"\n";
            throw lineNumber;
        }

    } catch(...) {
        std::cerr<<"Error in input file, line = "<<lineNumber<<"\n";
        inputFile.close();
        exit(-2);
    }


    // get the distances from a start vertex and print a result

    std::vector<int> distFromStartVertex = graph.BFS(startVertexId);
    
    /*
    for(auto dist: distFromStartVertex) {
        std::cout<<dist<<"\n";
    }
    */

    std::cout<<"Distances from a start vertex with id = "<<startVertexId<<": "<<"\n";
    for(int id=0; id<nVertices; id++) {
        std::cout<<"-> "<<id<<": "<<distFromStartVertex[id]<<"\n";
    }
    

    inputFile.close();

}