#include "Vertex.h"
#include <string>
#include <algorithm>
using namespace std;

Vertex::Vertex() { //initialize object 
    name = "";
}

Vertex::Vertex(string n) { //stores name inside vertex
    name = n;
}

string Vertex::getName() const {  //return name
    return name;
}

string Vertex::operator*() const {
    return name;
}

void Vertex::addNeighbor(string n) {
    neighbors.push_back(n);
}

void Vertex::removeNeighbor(string n) {
    neighbors.erase(remove(neighbors.begin(), neighbors.end(), n), neighbors.end());
}

vector<string> Vertex::incidentEdges() const {
    return neighbors;
}

bool Vertex::isAdjacentTo(string v) const {
    for (size_t i = 0; i < neighbors.size(); i++) {
        if (neighbors[i] == v) return true;
    }
    return false;
}

