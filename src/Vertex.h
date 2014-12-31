/**************************************************
 // Author: Abdullah Altawaitan
 // Date: 8 December 2014
 // Description: Vertex.h
 *********************************************************/
#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <string>

#define WHITE 0 
#define GRAY 1 
#define BLACK 2

class Edge; 

#ifndef BIG_NUMBER
#define BIG_NUMBER 1e12

class Vertex
{
public:
    // A Constructor
    Vertex(int id, std::string name);
    
    // A vector of edges that goes from the vertex to another vertex
    std::vector<Edge *> edges;
    
    // the color of the vertex 
    int color;
    
    // the distance of the vertex from another vertex
    double distance;
    
    // the predecessor vertex
    Vertex *pred;
    
    // A funtion that returns the Id of the vertex
    int getId() const { return this->Id; }
    
    // A funtion that returns the name of the vertex 
    std::string getName() const { return this->name; }
    
    // A funtion that returns the edge to a specified vertex
    Edge* getEdge(Vertex *adjVertex);


protected:
    // to store the ID of the Vertex
    int Id;
    
    // to store the name of the Vertex
    std::string name;
};

#endif // BIG_NUMBER
#endif // VERTEX_H