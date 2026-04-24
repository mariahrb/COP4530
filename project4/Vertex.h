#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <vector>

class Edge;
class Vertex {
private:
    std::string name;
    std::vector<std::string> neighbors; // adjacent vertex names

public:
    Vertex();
    Vertex(std::string n);

    std::string getName() const;
    std::string operator*() const;

    void addNeighbor(std::string n);
    void removeNeighbor(std::string n);

    std::vector<std::string> incidentEdges() const; // returns adjacent vertex names
    bool isAdjacentTo(std::string v) const;
};

#endif
