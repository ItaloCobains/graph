#include "graph.hpp"

void Graph::addNode(int nodeId)
{
    nodes.emplace_back(nodeId);
}

void Graph::addEdge(int sourceId, int targetId)
{
    edges.emplace_back(sourceId, targetId);
}

bool Graph::hasNode(int nodeId) const
{
    for (auto node : nodes)
    {
        if (node.id == nodeId)
        {
            return true;
        }
    }
    return false;
}

bool Graph::hasEdge(int sourceId, int targetId) const
{
    for (auto edge : edges)
    {
        if (edge.sourceId == sourceId && edge.targetId == targetId)
        {
            return true;
        }
    }
    return false;
}