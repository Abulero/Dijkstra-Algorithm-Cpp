#include <iostream>
#include <string>
#include <map>
#include <list>
#include "Graph.h"

using namespace std;

void Graph::AddNode(string name, map<string, int> edgesRaw)
{
    Node node;

    node.name = name;
    node.edgesRaw = edgesRaw;

    this->nodeList.push_back(node);
}

void Graph::StringsToPointers()
{
    for (list<Node>::iterator iter = this->nodeList.begin(), end = this->nodeList.end(); iter != end; iter++)
    {
        for(pair<string, int> edge : iter->edgesRaw)
        {
            for (list<Node>::iterator iter2 = this->nodeList.begin(), end = this->nodeList.end(); iter2 != end; iter2++)
            {
                if (iter2->name == edge.first)
                {
                    iter->edges.insert({ &(*iter2), edge.second });
                }
            }
        }
    }
}

void Graph::PrintSolution(list<Node> nodeList, string start, string end)
{
    int distance = 0;
    string path = "";

    for (Node node : nodeList)
    {
        if (node.name == end)
        {
            distance = node.distanceFromStart;

            Node* currentNode = &node;
            list<string> pathList;
            for (int i = 0; i < nodeList.size(); i++)
            {
                pathList.push_back(currentNode->name);

                currentNode = currentNode->pathOrigin;

                if (currentNode->name == start)
                {
                    pathList.push_back(start);
                    break;
                }
            }
            pathList.reverse();
            
            for (string nodeName : pathList)
            {
                path += nodeName + " -> ";
            }
            path.pop_back();
            path.pop_back();
            path.pop_back();
            path.pop_back();

            break;
        }
    }

    cout << "Shortest path according to Dijkstra's Algorithm:\n" << endl << "Distance: " << distance << " | Path: " << path << endl << endl;
    system("pause");
}

bool Graph::Contains(list<Node*> nodeList, Node* node)
{
    for (Node* tempNode : nodeList)
    {
        if (tempNode->name == node->name)
        {
            return true;
        }
    }

    return false;
}

bool Graph::EndReached(list<Node*> nodeList, string end)
{
    for (Node* node : nodeList)
    {
        if (node->name == end)
        {
            return true;
        }
    }

    return false;
}

void Graph::DijkstraSolution(string start, string end)
{
    Node* currentNode = NULL;
    list<Node*> visitedNodes;

    this->StringsToPointers();

    /* 
    Dijkstra algorithm

    Step 1: Assign 0 distance from start to the start node and infinite distance to the rest (already assigned as NULL). Also set the start node as the current node
    Step 2: Calculate the distance between the current node and its neighbors
    Step 3: Put the current node in the array of visited nodes
    Step 4: If the end node is marked as visited, end the algorithm
    Step 5: Mark the neighbor node closest to the current node as the new current node and go back to Step 2

    */

    // Step 1
    for (list<Node>::iterator iter = this->nodeList.begin(), end = this->nodeList.end(); iter != end; iter++)
    {
        if (iter->name == start)
        {
            currentNode = &(*iter);
            currentNode->distanceFromStart = 0;
            break;
        }
    }

    for (int i = 0; i < this->nodeList.size(); i++)
    {  
        // Step 2
        int shortestDistanceFromStart = -1;
        Node* closestNode = NULL;

        if (currentNode != NULL)
        {
            for (map<Node*, int>::iterator iter = currentNode->edges.begin(), end = currentNode->edges.end(); iter != end; iter++)
            {
                Node* neighborNode = iter->first;
                int neighborDistance = iter->second;

                if (!this->Contains(visitedNodes, neighborNode))
                {
                    if(neighborNode->distanceFromStart == -1)
                    {
                        neighborNode->distanceFromStart = 0;
                        neighborNode->distanceFromStart = currentNode->distanceFromStart + neighborDistance;
                        neighborNode->pathOrigin = currentNode;
                    }
                    else if (currentNode->distanceFromStart + neighborDistance < neighborNode->distanceFromStart)
                    {
                        neighborNode->distanceFromStart = currentNode->distanceFromStart + neighborDistance;
                        neighborNode->pathOrigin = currentNode;
                    }

                    if (shortestDistanceFromStart == -1 or neighborNode->distanceFromStart < shortestDistanceFromStart)
                    {
                        closestNode = neighborNode;
                        shortestDistanceFromStart = neighborNode->distanceFromStart;
                    }
                }
            }

            // Step 3
            visitedNodes.push_back(currentNode);

            // Step 4
            if (EndReached(visitedNodes, end))
            {
                break;
            }

            // Step 5
            currentNode = closestNode;
        }
    }

    this->PrintSolution(this->nodeList, start, end);
}