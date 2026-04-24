#ifndef VERTEX_H
#define VERTEX_H

#include <string>

class Edge;
class Vertex {
private:
    std::string name; //data in the vertex

public:
    Vertex();                  // constructor
    Vertex(std::string n);          // constructor w/ name

    std::string getName() const;

    std::string operator*() const;  // returns name
};

#endif
