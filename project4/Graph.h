#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include <string>
#include "Vertex.h"
#include "Edge.h"

class Graph {
private:
    std::vector<Vertex> verticesList;
    std::vector<Edge> edgesList;
    std::map<std::string, std::vector<std::string>> adjList;

    void buildFromFile(std::string filename);

public:
    Graph();
    Graph(std::string filename);

    bool hasVertex(std::string name) const; //check for a vertex w/ the name
    bool hasEdge(std::string a, std::string b) const; //check for an edge connecting values 
    Edge* findEdge(std::string a, std::string b); //find edge connecting values
    const Edge* findEdge(std::string a, std::string b) const;

    std::vector<Vertex> vertices() const;
    std::vector<Edge> edges() const;

    void insertVertex(std::string name);
    void insertEdge(std::string v, std::string w, std::string label);

    void eraseVertex(std::string v);
    void eraseEdge(std::string v, std::string w);

    void printIncidentEdges(std::string v) const;
    std::vector<std::string> findPath(std::string start, std::string end);

    void printGraph() const;
};

#endif