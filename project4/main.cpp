#include "Graph.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello!" << endl;

    string filename;
    cout << "Enter the file name: ";
    cin >> filename;

    Graph g(filename);

    cout << "Thank you. Your graph is ready." << endl;

    int choice;

    do {
        cout << "------------" << endl;
        cout << "What would you like to do?" << endl;
        cout << "------------" << endl;
        cout << "1. Find edges incident on a vertex" << endl;
        cout << "2. Find a path in the graph" << endl;
        cout << "3. Insert an edge" << endl;
        cout << "4. Erase a vertex" << endl;
        cout << "0. Exit" << endl;

        cin >> choice;

        if (choice == 1) {
            string v;
            cout << "Enter vertex: ";
            cin >> v;
            g.printIncidentEdges(v);
        }

        else if (choice == 2) {
            string v, u;
            cout << "Enter start and end vertices: ";
            cin >> v >> u;

            vector<string> path = g.findPath(v, u);

            for (size_t i = 0; i < path.size(); i++) { {
                cout << path[i];
                if (i != path.size() - 1) {
                    cout << " to ";
                }
            }
            cout << endl;
            }
        }
        
        else if (choice == 3) {
            string v, u, label;
            cout << "Enter v, u, and label: ";
            cin >> v >> u;
            cin.ignore();
            getline(cin, label);

            g.insertEdge(v, u, label);
        }

        else if (choice == 4) {
            string v;
            cout << "Enter vertex: ";
            cin >> v;
            g.eraseVertex(v);
        }

    } while (choice != 0);

    return 0;
}