#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <map>
#include <list>

using namespace std;

struct Node
{
    string name;
    int distanceFromStart = -1;
    Node* pathOrigin = NULL;
    map<string, int> edgesRaw;
    map<Node*, int> edges;
};

class Graph
{
    public:
    void AddNode(string name, map<string, int> edges);
    void DijkstraSolution(string startNode, string endNode);

    private:
    list<Node> nodeList;

    void StringsToPointers();
    void PrintSolution(list<Node> nodeList, string start, string end);
    bool Contains(list<Node*> nodeList, Node* node);
    bool EndReached(list<Node*> nodeList, string end);
};

#endif