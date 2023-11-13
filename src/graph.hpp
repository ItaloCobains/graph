#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <string>

class Node
{
public:
  int id;
  Node(int nodeId) : id(nodeId) {}
};

class Edge
{
public:
  int sourceId;
  int targetId;

  Edge(int source, int target) : sourceId(source), targetId(target) {}
};

class Graph
{
private:
  std::vector<Node> nodes;
  std::vector<Edge> edges;

public:
  void addNode(int nodeId);
  void addEdge(int sourceId, int targetId);
  bool hasNode(int nodeId) const;
  bool hasEdge(int sourceId, int targetId) const;
  void removeEdge(int sourceId, int targetId);
  void removeNode(int nodeId);
  std::vector<int> getNeighbors(int nodeId) const;
  std::vector<int> getNodes() const;
  std::string toString() const;
  std::vector<int> getInNeighbors(int nodeId) const;
};

#endif