#ifndef EDGE_H
#define EDGE_H

#include <string>

class Vertex;

class Edge {
private:
    std::string v1;
    std::string v2; //endpoints
    std::string label; //edge value

public:
    Edge();
    Edge(std::string a, std::string b, std::string l);

    std::string getV1() const;
    std::string getV2() const;
    std::string getLabel() const;

    std::string operator*() const; //returns main stored value

    bool isIncidentOn(std::string v) const; //check if vertex is an endpoint
    std::string opposite(std::string v) const; //returns opposite vertex
    bool connects(std::string a, std::string b) const; //checks connections
    bool isAdjacentTo(const Edge& e) const; //checks if vertex share endpoint
};

#endif