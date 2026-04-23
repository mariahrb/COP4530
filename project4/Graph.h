#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include <string>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

class Graph {
private:
    vector<Vertex> verticesList;
    vector<Edge> edgesList;
    map<string, vector<string>> adjList;

    void buildFromFile(string filename);

public:
    Graph();
    Graph(string filename);

    bool hasVertex(string name) const; //check for a vertex w/ the name
    bool hasEdge(string a, string b) const; //check for an edge connecting values 
    Edge* findEdge(string a, string b); //find edge connecting values
    const Edge* findEdge(string a, string b) const;

    vector<Vertex> vertices() const;
    vector<Edge> edges() const;

    void insertVertex(string name);
    void insertEdge(string v, string w, string label);

    void eraseVertex(string v);
    void eraseEdge(string v, string w);

    void printIncidentEdges(string v) const;
    vector<string> findPath(string start, string end);

    void printGraph() const;
};

#endif