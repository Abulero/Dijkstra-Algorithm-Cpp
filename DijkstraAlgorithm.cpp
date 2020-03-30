/*
---Author: André Gomes Cecchi
---Date: 03/27/2020

---Choices:
-Not to use a NodeType enum for each node to specify if it's a START, END or "WAY" node. The reason for this decision is to let the user to change the start and end nodes
editing only the graph.Solve() line in the main function, thus allowing for a more fluid study of the graph's solutions.
-String for node names instead of a char to allow the user to choose real world entities as nodes (cities etc)

---Guide:
-Instantiate the Graph class
-Use add_nodes to build your graph's nodes and edges
-The "neighbors" argument of the add_node method takes a dictionary in which the keys are the node names and values the
distance from the node you are creating and that neighbor
-Call dijkstra_solution to print the shortest path from "start" to "end" according to Dijkstra's Algorithm

*/

#include <iostream>
#include <map>
#include <list>
#include <string>
#include "Graph/Graph.h"

using namespace std;

int main()
{
    Graph graph;

    graph.AddNode("A", { {"B", 5}, {"C", 4} });
    graph.AddNode("B", { {"A", 5}, {"C", 4}, {"D", 1}, {"E", 7} });
    graph.AddNode("C", { {"A", 4}, {"B", 4}, {"E", 8}, {"F", 10} });
    graph.AddNode("D", { {"B", 1}, {"E", 1} });
    graph.AddNode("E", { {"B", 7}, {"C", 8}, {"D", 1}, {"F", 2} });
    graph.AddNode("F", { {"C", 10}, {"E", 2} });

    graph.DijkstraSolution("A", "F");

    return 0;
}