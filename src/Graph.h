/**************************************************
 // Author: Abdullah Altawaitan
 // Date: 8 December 2014
 // Description: Graph.h
 *********************************************************/
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream> 

#include "Vertex.h"
#include "Edge.h"

class Graph 
{
public:
    // To add a vertex in the vertices vector
	bool addVertex(Vertex *vertex);
    
    // To get the vertices
	std::vector<Vertex *> getVertices() { return vertices; }
    
    // To get a vertex by the Id from the vertices vector
	Vertex* getVertex(int id);
    
    // Initilize the vertices
    void InitVertices();
    
    // A function for Dijkstra Shortest Path
    bool DijkstraShortestPath(Vertex *s);
    
    // A function for Dijkstra Most Reliable  Path
    bool DijkstraReliablePath(Vertex *s);
    
    // To find the Shortest Path
    bool Relax(Vertex *v, Edge *e);
    
    // To find the Most Reliable Path
    bool Reliable(Vertex *v, Edge *e);
    
    // To parse a file
    bool parser(char* filename);
    
    // To analyze the Shortest Path and print out the results
    bool analyzeShortestPath(char *argv1, char *argv2);
    
    // To analyze the Most Reliable Path and print out the results
    bool analyzeReliablePath(char *argv1, char *argv2);

protected:
    // A vector of the vertices 
	std::vector<Vertex *> vertices;
};

#endif