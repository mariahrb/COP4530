#include "Vertex.h"
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

string Vertex::operator*() const { //return name using *
    return name;
}

