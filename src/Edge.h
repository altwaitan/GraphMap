/**************************************************
 // Author: Abdullah Altawaitan
 // Date: 8 December 2014
 // Description: Edge.h
 *********************************************************/
#ifndef EDGE_H
#define EDGE_H

class Vertex; 

class Edge 
{
public:
    // A Constructor
    Edge(Vertex *adjVertex, double min, double max);
    
    // A pointer to an adjecent vertex
    Vertex *adjVertex;
    
    // Minimum time of the edge
    double min;
    
    // Maximum time of the edge
    double max;
};

#endif 