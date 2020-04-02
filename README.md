# DijkstraAlgorithmPython

Simple implementation of a Dijkstra algorithm in C++.

# Notes

I consciously decided not to approach the problem with an adjency list or matrix so that the code can be more intuitive and easy to understand, although being less performatic.

# How to use

Instantiate the Graph class.

```c++
Graph graph;
```

To build your graph, call the addNode method to create each individual node and its edges. The first argument of the addNode method takes a dictionary in which the keys are the node names and the values are the distance from the node you are creating and that neighbor.

```
graph.AddNode("A", { {"B", 5}, {"C", 4} });
graph.AddNode("B", { {"A", 5}, {"C", 4}, {"D", 1}, {"E", 7} });
graph.AddNode("C", { {"A", 4}, {"B", 4}, {"E", 8}, {"F", 10} });
graph.AddNode("D", { {"B", 1}, {"E", 1} });
graph.AddNode("E", { {"B", 7}, {"C", 8}, {"D", 1}, {"F", 2} });
graph.AddNode("F", { {"C", 10}, {"E", 2} });
```

To solve the graph you built, simply call the dijkstraSolution method. The first argument is the desired starting node and the second argument is the end node. The program shall then print out the minimum distance and path, according to Dijkstra's Algorithm.

```
graph.DijkstraSolution("A", "F");
```
