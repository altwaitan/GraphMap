/**************************************************
 // Author: Abdullah Altawaitan
 // Date: 8 December 2014
 // Description: Graph.cpp
 *********************************************************/
#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"

// To add a vertex in the vertices vector
bool Graph::addVertex(Vertex *vertex)
{
    bool result = true;
    
    // Checking if the vertex exists
    if (vertex != NULL)
    {
        // Loop through the vertices vector to check if the vertex already exists
        for (std::vector<Vertex *>::iterator it=vertices.begin(); it != vertices.end(); it++)
        {
            Vertex *v = *it;
            if (v->getId() == vertex->getId())
            {
                result = false;
                break;
            }
        }
        
        // if the vertex does not exist in the vertices vector, then push it back in the vector
        if (result == true)
        {
            vertices.push_back(vertex);
        }
    }
    
    return result;
}

// To get a vertex by the Id from the vertices vector
Vertex* Graph::getVertex(int id)
{
    Vertex *result = NULL;
    
    // // Loop through the vertices vector to find the vertex
    for (std::vector<Vertex *>::iterator it=vertices.begin(); it != vertices.end(); it++)
    {
        if ((*it)->getId() == id)
        {
            result = *it;
        }
    }
    
    return result; 
}

// Initilize the vertices
void Graph::InitVertices()
{
    int i = 0;
    // Get the size of the vertices vector
    int size = this->vertices.size();
    
    // Loop through the vertices vector and initilize the distance to BIG_NUMBER and predecessor to NULL
    for (i = 0; i < size; i++)
    {
        this->vertices.at(i)->distance = BIG_NUMBER;
        this->vertices.at(i)->pred = NULL; 
    }
    
    return;
}

// A function for Dijkstra Shortest Path
bool Graph::DijkstraShortestPath(Vertex *s)
{
    bool result = false;
    
    // Check if the vertex exists
    if (s != NULL)
    {
        result = true;
        
        // Initilize the vertices
        this->InitVertices();
    
        // 1. Set Distance to zero
        s->distance = 0;
    
        // 2. Create a vector Queue and push back the vertices
        std::vector<Vertex *> queue;
        int i = 0;
        int index = 0;
        int size = this->vertices.size();
        for (i = 0; i < size; i++)
        {
            queue.push_back(this->vertices.at(i));
        }
    
        // 3. Loop through the queue until it is empty
        Vertex *v = queue.at(0);
        double minDistance = 0;
        while (!queue.empty())
        {
            minDistance = queue.at(0)->distance;
            v = queue.at(0);
            index = 0; 
            // Loop to find the minimum distance and grap the vertex
            for (i = 0; i < queue.size(); i++)
            {
                if (queue.at(i)->distance < minDistance)
                {
                    minDistance = queue.at(i)->distance;
                    v = queue.at(i);
                    index = i;
                }
            }
            
            // Pop out the vertex from the Queue
            queue.erase(queue.begin() + index);
        
            // Loop through all edges of the Poped out Vertex
            int size = v->edges.size();
            for (i = 0; i < size; i++)
            {
                // Find the Shortest Path
                Relax(v, v->edges.at(i));
            }
        }
        
    }

    return result;
}

// A function for Dijkstra Most Reliable  Path
bool Graph::DijkstraReliablePath(Vertex *s)
{
    bool result = false;
    
    // Check if the vertex exists
    if (s != NULL)
    {
        result = true;
        
        // Initilize the vertices
        this->InitVertices();
        
        // 1. Set Distance to zero
        s->distance = 0;
        
        // 2. Create a vector Queue and push back the vertices
        std::vector<Vertex *> queue;
        int i = 0;
        int index = 0;
        int size = this->vertices.size();
        for (i = 0; i < size; i++)
        {
            queue.push_back(this->vertices.at(i));
        }
        
        // 3. Loop through the queue until it is empty
        Vertex *v = queue.at(0);
        double minDistance = 0;
        while (!queue.empty())
        {
            minDistance = queue.at(0)->distance;
            v = queue.at(0);
            index = 0;
            // Loop to find the minimum distance and grap the vertex
            for (i = 0; i < queue.size(); i++)
            {
                if (queue.at(i)->distance < minDistance)
                {
                    minDistance = queue.at(i)->distance;
                    v = queue.at(i);
                    index = i;
                }
            }
            
            // Pop out the vertex from the Queue
            queue.erase(queue.begin() + index);
            
            // Loop through all edges of the Poped out Vertex
            int size = v->edges.size();
            for (i = 0; i < size; i++)
            {
                // Find the Most Reliable Path
                Reliable(v, v->edges.at(i));
            }
        }
        
    }
    
    return result;
}

// To find the Shortest Path
bool Graph::Relax(Vertex *v, Edge *e)
{
    bool result = false;
    
    // Check if both vertex and edge exist
    if (v != NULL && e != NULL)
    {
        result = true;
        Vertex *d = e->adjVertex;
        
        // Check if the stored distance of the vertex is greater than the new distance way
        if (d->distance > (v->distance + e->min))
        {
            // Set the distance to the new distance way
            d->distance = v->distance + e->min;
            
            // Set the predecessor to the vertex v
            d->pred = v;
        }
    }
    
    return result;
    
}

// To find the Most Reliable Path
bool Graph::Reliable(Vertex *v, Edge *e)
{
    bool result = false;
    
    // Check if both vertex and edge exist
    if (v != NULL && e != NULL)
    {
        result = true;
        Vertex *d = e->adjVertex;
        
        // Check if the stored distance of the vertex is greater than the new distance way
        if (d->distance > (v->distance + (e->max - e->min)))
        {
            // Set the distance to the new distance way
            d->distance = v->distance + (e->max - e->min);
            
            // Set the predecessor to the vertex v
            d->pred = v;
        }
    }
    
    return result;
}

// To parse a file
bool Graph::parser(char* filename)
{
    bool result = false;
    
    // Opening a file to read the data
    std::fstream file;
    file.open(filename);
    
    // Variables
    size_t find;
    std::string readLine;
    int id = 0;
    std::string name = "";
    int start = 0;
    int end = 0;
    double min = 0;
    double max = 0;
    int location = 0;
    std::string idString;
    
    if (file.is_open())
    {
        result = true;
        
        // Get the first line
        getline(file, readLine);
        
        // Look at the "WAYPOINTS:" keyword in the file
        find = readLine.find("WAYPOINTS:");
        
        // If "WAYPOINTS:" has been found
        if(find != std::string::npos)
        {
            // Loop through the file until the end
            while (!file.eof())
            {
                find = readLine.find("STREETS:");
                if (find == std::string::npos)
                {
                    // Get the next line
                    getline(file, readLine);
                    
                    if (readLine.empty() != true)
                    {
                        // Stringstream to store the line
                        std::stringstream stream(readLine);
                        
                        // Putting the values in the variables
                        stream >> id;
                        std::stringstream intStream;
                        intStream << id;
                        idString = intStream.str();
                        
                        // Erasing the id from readLine
                        readLine.erase(0, idString.size());
                        
                        // Removing '\t' if found
                        find = readLine.find("\t");
                        
                        if (find != std::string::npos)
                        {
                            readLine.erase(find, find + 1);
                        }
                        
                        // Removing Whitespaces before the string if found
                        while (readLine.at(location) == ' ')
                        {
                            readLine.erase(0, location + 1);
                        }
                        
                        // Putting the name of the vertex to the name variable
                        name = readLine;
                        
                        // Check that the id is NOT already exists in the vertices
                        if (this->getVertex(id) == NULL)
                        {
                            // Create a new Vertex with a new ID and name
                            Vertex *v = new Vertex(id, name);
                            
                            // Add the Vertex to the vertices vector in the Graph
                            this->addVertex(v);
                        }
                        // If the id is already exists in the vertices
                        else
                        {
                            // Print out the statement
                            std::cout << "Error: Duplicate Waypoint id" << std::endl;
                            return false;
                        }
                    }
                    else
                    {
                        // Read the next line
                        getline(file, readLine);
                        // Break to STREETS
                        break;
                    }
                }
                else
                {
                    // Break to STREETS
                    break;
                }
            }
            
            // HERE FOR STREETS
            find = readLine.find("STREETS:");
            if (find != std::string::npos)
            {
                getline(file, readLine);
                if (readLine.empty() != true)
                {
                    while (!file.eof())
                    {
                        // Get the next line after "STREETS:"
                        getline(file, readLine);
                        
                        // If the line is NOT empty
                        if (readLine.empty() != true)
                        {
                            // Stringstream to store the line
                            std::stringstream stream2(readLine);
                            
                            // Putting the values in the variables
                            stream2 >> start;
                            stream2 >> end ;
                            stream2 >> min;
                            stream2 >> max;
                            
                            // Check if Min greater than Max
                            if (min > max)
                            {
                                // Print out the statment
                                std::cout << "Error: minTravelTime  is greater than maxTravelTime" << std::endl;
                                return false;
                            }
                            
                            // Check if either of Max or Min is less than zero
                            if (min < 0 || max < 0)
                            {
                                // Print out the statment
                                std::cout << "Error: either of Max or Min is less than zero" << std::endl;
                                return false;
                            }
                            
                            // Check that both startId and endId exist, then create an edge and push it the startId edges vector
                            if (this->getVertex(start) != NULL && this->getVertex(end) != NULL)
                            {
                                Vertex *v1 = this->getVertex(start);
                                Vertex *v2 = this->getVertex(end);
                                
                                // Check if the edge is already exists
                                if (v1->getEdge(v2) == NULL)
                                {
                                    Edge *e = new Edge(v2, min, max);
                                    v1->edges.push_back(e);
                                }
                                else
                                {
                                    std::cout << "Error: Duplicate of edges" << std::endl;
                                    return false;
                                }
                            }
                            // Check that both startId and endId Do not exist
                            else
                            {
                                // Print out the statement
                                std::cout << "Error: One/both of the Id's does not exist" << std::endl;
                                return false;
                            }
                        }
                    } // end of file.eof
                }
                else
                {
                    std::cout << "Error: The file is not appropriate" << std::endl;
                    return false;
                }
            }
            else
            {
                std::cout << "Error: The file is not appropriate" << std::endl;
                return false;
            }
        }
        else
        {
            std::cout << "Error: File is empty OR not appropriate file" << std::endl;
            return false;
        }
    }

    return result;
}

// To analyze the Shortest Path and print out the results
bool Graph::analyzeShortestPath(char *argv1, char *argv2)
{
    bool result = true;
    
    // Store the startId and endId from the command line argument
    int a = atoi(argv1);
    int b = atoi(argv2);
    
    // Get the Vertex for both startId and endId
    Vertex *s = this->getVertex(a);
    Vertex *e = this->getVertex(b);
    
    // If either startId or endId does not exist
    if (s == NULL || e == NULL)
    {
        return false;
    }
    
    // if both s and e exist
    if (result == true)
    {
        // Dijkstra Shortest Path
        this->DijkstraShortestPath(s);
        
        // if No route found
        if (e->distance == BIG_NUMBER)
        {
            std::cout << "No routes found." << std::endl;
            return false;
        }
        
        
        if (result == true)
        {
            // Find the minTime and maxTime
            Vertex *temp1 = e;
            double minTime = 0;
            double maxTime = 0;
            
            // Loop from the endId to the startId and calculate the minimum time and maximum time
            while (temp1->pred != NULL)
            {
                minTime = minTime + (temp1->pred)->getEdge(temp1)->min;
                maxTime = maxTime + (temp1->pred)->getEdge(temp1)->max;
                
                temp1 = temp1->pred;
            }
        
            // Printing the output
            std::cout << "Shortest path: " << argv1 << " to " << argv2 << " (" << minTime << " to " << maxTime << " )" << std::endl;
            std::cout << " startWp" << std::endl;

            // Printing the Route
            Vertex *temp = e;
        
            // A vector to store the vertices route
            std::vector<Vertex *> printingBox;
        
            // Loop from the endId to the startId
            while (temp->pred != NULL)
            {
                // Push the vertices to the back
                printingBox.push_back(temp);
            
                // Go to the previous vertex
                temp = temp->pred;
            }
        
            // Exception for the startId
            printingBox.push_back(temp);

            // Printing the Route from the start to the end
            while (!printingBox.empty())
            {
                temp = printingBox.back();
                std::cout << " " <<temp->getName() << std::endl;
                printingBox.pop_back();
            }
        
            std::cout << " endWp" << std::endl << std::endl;
        }
        
    }
    
    return result;
}

// To analyze the Most Reliable Path and print out the results
bool Graph::analyzeReliablePath(char *argv1, char *argv2)
{
    bool result = true;
    
    // Store the startId and endId from the command line argument
    int a = atoi(argv1);
    int b = atoi(argv2);
    
    // Get the Vertex for both startId and endId
    Vertex *s = this->getVertex(a);
    Vertex *e = this->getVertex(b);
    
    // If either startId or endId does not exist
    if (s == NULL || e == NULL)
    {
        result = false;
    }
    
    // if both s and e exist
    if (result == true)
    {
        // Dijkstra Most Reliable Path
        this->DijkstraReliablePath(s);
        
        // if No route found// if No route found
        if (e->distance == BIG_NUMBER)
        {
            std::cout << "No routes found." << std::endl;
            return false;
        }
    
        if (result == true)
        {
            // Find the minTime and maxTime
            Vertex *temp1 = e;
            double minTime = 0;
            double maxTime = 0;
            
            // Loop from the endId to the startId and calculate the minimum time and maximum time
            while (temp1->pred != NULL)
            {
                minTime = minTime + (temp1->pred)->getEdge(temp1)->min;
                maxTime = maxTime + (temp1->pred)->getEdge(temp1)->max;
                
                temp1 = temp1->pred;
            }
        
            // Printing the output
            std::cout << "Most reliable path: " << argv1 << " to " << argv2 << " (" << minTime << " to " << maxTime << " )" << std::endl;
            std::cout << " startWp" << std::endl;
        
            // Printing the Route
            Vertex *temp = e;
            
            // A vector to store the vertices route
            std::vector<Vertex *> printingBox;
            
            // Loop from the endId to the startId
            while (temp->pred != NULL)
            {
                // Push the vertices to the back
                printingBox.push_back(temp);
                
                // Go to the previous vertex
                temp = temp->pred;
            }
            
            // Exception for the startId
            printingBox.push_back(temp);
        
            // Printing the Route from the start to the end
            while (!printingBox.empty())
            {
                temp = printingBox.back();
                std::cout << " " <<temp->getName() << std::endl;
                printingBox.pop_back();
            }
        
            std::cout << " endWp" << std::endl << std::endl;
        }
    }
    
    return result;
}