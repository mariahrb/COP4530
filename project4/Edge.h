#ifndef EDGE_H
#define EDGE_H

#include <string>
using namespace std;

class Edge {
private:
    string v1;
    string v2; //endpoints
    string label; //edge value

public:
    Edge();
    Edge(string a, string b, string l);

    string getV1() const;
    string getV2() const;
    string getLabel() const;

    string operator*() const; //returns main stored value

    bool isIncidentOn(string v) const; //check if vertex is an endpoint
    string opposite(string v) const; //returns opposite vertex
    bool connects(string a, string b) const; //checks connections
    bool isAdjacentTo(const Edge& e) const; //checks if vertex share endpoint
};

#endif