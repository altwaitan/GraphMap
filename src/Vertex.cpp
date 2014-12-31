/**************************************************
 // Author: Abdullah Altawaitan
 // Date: 8 December 2014
 // Description: Vertex.cpp
 *********************************************************/
#include "Vertex.h"
#include "Edge.h"

// A Constructor
Vertex::Vertex(int id, std::string name)
	: color(WHITE), distance(BIG_NUMBER),  Id(id), name(name)
{
	// Nothing
}

// A funtion that returns the edge to a specified vertex
Edge* Vertex::getEdge(Vertex *adjVertex)
{
    // Create an Edge pointer
    Edge *e = NULL;
    int i = 0;
    // Get the size of the edges vector
    int size = this->edges.size();
    
    // Loop through the edges vector and find the edge that connects to adjVertex
    for (i = 0; i < size; i++)
    {
        if (this->edges.at(i)->adjVertex == adjVertex)
        {
            e = this->edges.at(i);
        }
    }
    return e;
}

