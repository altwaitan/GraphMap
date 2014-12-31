/**************************************************
// Author: Abdullah Altawaitan 
// Date: 8 December 2014
// Description: Application named weighs that searches for the optimal route to travel to a location
// based on the shortest, and longest, potential travel times along a route.
*********************************************************/
#include <iostream>
#include "Graph.h"

int main( int argc, char *argv[])
{
	// Checking the command line argument
	if (argc != 4)
	{
        std::cout << std::endl << "Usage: " << argv[0] << " start end streetMapGraphFile" << std::endl;
		return -1; 
	}
    
    // Create a graph object
    Graph graph;
    
    // Parser the file into the graph
    if ( graph.parser(argv[3]) == false )
    {
        return -1;
    }
    
    // analyze the shortest path
    if ( graph.analyzeShortestPath(argv[1], argv[2]) == false )
    {
        return -1;
    }
    
    // analyze the most reliable path
    if ( graph.analyzeReliablePath(argv[1], argv[2]) == false )
    {
        return -1; 
    }
    
    return 0;
}