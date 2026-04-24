#include "Edge.h"
#include <string>
using namespace std;

//constructors
Edge::Edge() {
    v1 = "";
    v2 = "";
    label = "";
}

Edge::Edge(string a, string b, string l) {
    v1 = a;
    v2 = b;
    label = l;
}

//getters
string Edge::getV1() const {
    return v1;
}

string Edge::getV2() const {
    return v2;
}
string Edge::getLabel() const {
    return label;
}

//operator*
string Edge::operator*() const {
    return label;
}

//isIncidentOn
bool Edge::isIncidentOn(string v) const {
    if(v == v1 || v == v2){
        return true;
    }

    return false;
}

//opposite
string Edge::opposite(string v) const {
    if(v == v1){
        return v2;
    }
    else if(v == v2){
        return v1;
    }
    else{
        return "";
    }
}

//connects 
bool Edge::connects(string a, string b) const {
    if((a == v1 && b == v2) || (a == v2 && b == v1)){
        return true;
    }

    return false;
}

//isAdjacentTo
bool Edge::isAdjacentTo(const Edge& e) const {
    if (isIncidentOn(e.getV1()) || isIncidentOn(e.getV2())) {
        return true;
    }
    return false;
}