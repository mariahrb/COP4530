#include "Graph.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <queue>
using namespace std;

Graph::Graph() {
}

Graph::Graph(string filename) {
    buildFromFile(filename);
}

bool Graph::hasVertex(string name) const {
    return adjList.find(name) != adjList.end();
}

bool Graph::hasEdge(string a, string b) const {
    for (std::size_t i = 0; i < edgesList.size(); i++) {
        if (edgesList[i].connects(a, b)) {
            return true;
        }
    }
    return false;
}

void Graph::insertVertex(string name) {
    if (!hasVertex(name)) { // if vertex does not exist
        verticesList.push_back(Vertex(name)); // add it
        adjList[name] = vector<string>(); // create adjacency list
    }
}

void Graph::insertEdge(string v, string w, string label) {
    if (!hasVertex(v) || !hasVertex(w)) { // if vertex doesn't exist
        cout << "Error: one or both vertices do not exist" << endl;
        return;
    }

    if (hasEdge(v, w)) { // if edge exists
        cout << "Edge already exists" << endl;
        return;
    }

    edgesList.push_back(Edge(v, w, label)); // create edge
    adjList[v].push_back(w);
    adjList[w].push_back(v);

    // keep Vertex neighbor lists in sync
    for (size_t i = 0; i < verticesList.size(); i++) {
        if (verticesList[i].getName() == v) verticesList[i].addNeighbor(w);
        else if (verticesList[i].getName() == w) verticesList[i].addNeighbor(v);
    }

    cout << "Edge inserted" << endl;
}

Edge* Graph::findEdge(string a, string b) {
    for (std::size_t i = 0; i < edgesList.size(); i++) {
        if (edgesList[i].connects(a, b)) {
            return &edgesList[i];
        }
    }
    return nullptr;
}

const Edge* Graph::findEdge(string a, string b) const {
    for (std::size_t i = 0; i < edgesList.size(); i++) {
        if (edgesList[i].connects(a, b)) {
            return &edgesList[i];
        }
    }
    return nullptr;
}

// return all vertices
vector<Vertex> Graph::vertices() const {
    return verticesList;
}

// return all edges
vector<Edge> Graph::edges() const {
    return edgesList;
}

void Graph::printIncidentEdges(string v) const {
    if (!hasVertex(v)) {
        cout << "Error: vertex does not exist" << endl;
        return;
    }

    for (std::size_t i = 0; i < adjList.at(v).size(); i++) {
        string neighbor = adjList.at(v)[i];

        const Edge* e = findEdge(v, neighbor);
        if (e != nullptr) {
            cout << v << " to " << neighbor << " is " << e->getLabel() << " mi" << endl;
        }
    }
}

void Graph::eraseEdge(string v, string w) {
    if (!hasEdge(v, w)) {
        cout << "Error: edge does not exist" << endl;
        return;
    }

    // remove w from v's neighbor list
    adjList[v].erase(
        remove(adjList[v].begin(), adjList[v].end(), w),
        adjList[v].end()
    );

    // remove v from w's neighbor list
    adjList[w].erase(
        remove(adjList[w].begin(), adjList[w].end(), v),
        adjList[w].end()
    );

    // remove edge object from edgesList
    for (std::size_t i = 0; i < edgesList.size(); i++) {
        if (edgesList[i].connects(v, w)) {
            edgesList.erase(edgesList.begin() + i);
            break;
        }
    }

    // keep Vertex neighbor lists in sync
    for (std::size_t i = 0; i < verticesList.size(); i++) {
        if (verticesList[i].getName() == v) verticesList[i].removeNeighbor(w);
        else if (verticesList[i].getName() == w) verticesList[i].removeNeighbor(v);
    }
}

void Graph::eraseVertex(string v) {
    if (!hasVertex(v)) {
        cout << "Error: vertex does not exist" << endl;
        return;
    }

    vector<string> neighbors = adjList[v];

    for (std::size_t i = 0; i < neighbors.size(); i++) {
        eraseEdge(v, neighbors[i]);
    }

    adjList.erase(v);

    for (std::size_t i = 0; i < verticesList.size(); i++) {
        if (verticesList[i].getName() == v) {
            verticesList.erase(verticesList.begin() + i);
            break;
        }
    }

    cout << "Vertex removed" << endl;
}

vector<string> Graph::findPath(string start, string end) {
    vector<string> path;

    if (!hasVertex(start) || !hasVertex(end)) {
        cout << "Error: one or both vertices do not exist" << endl;
        return path;
    }

    map<string, bool> visited;
    map<string, string> parent;
    queue<string> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (current == end) {
            break;
        }

        for (std::size_t i = 0; i < adjList[current].size(); i++) {
            string neighbor = adjList[current][i];

            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    if (!visited[end]) {
        cout << "No path found" << endl;
        return path;
    }

    string current = end;

    while (current != start) {
        path.push_back(current);
        current = parent[current];
    }

    path.push_back(start);
    reverse(path.begin(), path.end());

    if (path.size() < 3) {
        cout << "Path must contain at least 3 vertices" << endl;
        path.clear();
    }

    return path;
}

void Graph::buildFromFile(string filename) {
    ifstream file(filename);

    if (!file) {
        cout << "Error: could not open file" << endl;
        return;
    }

    string line;

    // read vertices
    getline(file, line);
    stringstream ss(line);
    string vertexName;

    while (ss >> vertexName) {
        insertVertex(vertexName);
    }

    // read edges
    while (getline(file, line)) {
        string v1, v2, label;
        stringstream edgeStream(line);

        getline(edgeStream, v1, '\t');
        getline(edgeStream, v2, '\t');
        getline(edgeStream, label);

        insertEdge(v1, v2, label);
    }

    file.close();
}

void Graph::printGraph() const {
    for (auto it = adjList.begin(); it != adjList.end(); it++) {
        cout << it->first << ": ";

        for (std::size_t i = 0; i < it->second.size(); i++) {
            cout << it->second[i] << " ";
        }

        cout << endl;
    }
}