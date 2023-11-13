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

std::vector<int> Graph::getNeighbors(int nodeId) const
{
    std::vector<int> neighbors;
    for (auto edge : edges)
    {
        if (edge.sourceId == nodeId)
        {
            neighbors.push_back(edge.targetId);
        }
    }
    return neighbors;
}

std::vector<int> Graph::getNodes() const
{
    std::vector<int> nodeIds;
    for (auto node : nodes)
    {
        nodeIds.push_back(node.id);
    }
    return nodeIds;
}

std::string Graph::toString() const
{
    std::string result = "";
    for (auto node : nodes)
    {
        result += std::to_string(node.id) + " -> ";
        for (auto edge : edges)
        {
            if (edge.sourceId == node.id)
            {
                result += std::to_string(edge.targetId) + " ";
            }
        }
        result += "\n";
    }
    return result;
}

std::vector<int> Graph::getInNeighbors(int nodeId) const
{
    std::vector<int> neighbors;
    for (auto edge : edges)
    {
        if (edge.targetId == nodeId)
        {
            neighbors.push_back(edge.sourceId);
        }
    }
    return neighbors;
}

void Graph::removeEdge(int sourceId, int targetId)
{
    for (auto it = edges.begin(); it != edges.end(); ++it)
    {
        if (it->sourceId == sourceId && it->targetId == targetId)
        {
            edges.erase(it);
            break;
        }
    }
}

void Graph::removeNode(int nodeId)
{
    for (auto it = nodes.begin(); it != nodes.end(); ++it)
    {
        if (it->id == nodeId)
        {
            nodes.erase(it);
            break;
        }
    }
    for (auto it = edges.begin(); it != edges.end(); ++it)
    {
        if (it->sourceId == nodeId || it->targetId == nodeId)
        {
            edges.erase(it);
            --it;
        }
    }
}
