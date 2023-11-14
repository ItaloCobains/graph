import { Graph } from './graph';


const graph = new Graph();
graph.addNode(1);
graph.addNode(2);
graph.addEdge(1, 2);

console.log(graph.toString());

graph.removeNode(1);

console.log(graph.toString());

const nodes = graph.getNodes();

console.log(nodes);

console.log(graph.hasNode(2));

console.log(graph.hasEdge(1, 2));

console.log(graph.getNeighbors(2));

console.log(graph.getInNeighbors(2));

console.log(graph.getOutNeighbors(2));

console.log(graph.getEdge(1, 2));

console.log(graph.getDegree(2));

console.log(graph.getInDegree(2));

console.log(graph.getOutDegree(2));

console.log(graph.isEmpty());

console.log(graph.getNumNodes());

console.log(graph.getNumEdges());

graph.clear();
