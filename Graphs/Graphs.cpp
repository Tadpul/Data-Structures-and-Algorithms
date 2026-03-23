#include "Graphs.h"
#include <iostream>

// graph member functions
bool Graph::addVertex(std::string vertex)
{
    if (graph.count(vertex) == 0)
    {
        graph[vertex];
        return true;
    }
    return false;
}

bool Graph::addEdge(std::string vertex1, std::string vertex2)
{
    if (graph.count(vertex1) == 1 && graph.count(vertex2) == 1)
    {
        graph.at(vertex1).insert(vertex2);
        graph.at(vertex2).insert(vertex1);
        return true;
    }
    return false;
}

bool Graph::removeEdge(std::string vertex1, std::string vertex2)
{
    if (graph.count(vertex1) == 1 && graph.count(vertex2) == 1)
    {
        if (graph.at(vertex1).count(vertex2) == 1 && graph.at(vertex2).count(vertex1) == 1) 
        {
            graph.at(vertex1).erase(vertex2);
            graph.at(vertex2).erase(vertex1);
            return true;
        }
        return false;
    }
    return false;
}

bool Graph::removeVertex(std::string vertex)
{
    if (graph.count(vertex) == 1)
    {
        // iterates through all vertices and eliminates any edge that contains removed vertex
        for (std::string edge : graph.at(vertex))
        {
            graph.at(edge).erase(vertex);
        }

        // erases the vertex
        graph.erase(vertex);
        return true;
    }
    return false;
}

void Graph::printGraph()
{
    for (const auto& vertex : graph)
    {
        std::cout << vertex.first << ": { ";
        for (std::string edge : vertex.second) {std::cout << edge << ' ';}
        std::cout << "}\n";
    }
}       
