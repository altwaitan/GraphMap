/**************************************************
 // Author: Abdullah Altawaitan
 // Date: 8 December 2014
 // Description: Edge.cpp
 *********************************************************/

#include "Edge.h"
#include "Vertex.h"

// A Constructor
Edge::Edge(Vertex *adjVertex, double min, double max)
	: adjVertex(adjVertex), min(min), max(max)
{
	// Nothing
}