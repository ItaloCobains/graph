import { Graph } from './graph';
;

const graph = new Graph();
graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addEdge(1, 2);
graph.addEdge(2, 3);
    
console.log(graph.getNodes())
console.log(graph.toString())
console.log(graph.getNeighbors(1))
console.log(graph.getNeighbors(2))
console.log(graph.getNeighbors(3))

// graph.addNode(1);
// graph.addNode(2);
// graph.addEdge(1, 2);

// console.log(graph.toString());

// graph.removeNode(1);

// console.log(graph.toString());

// const nodes = graph.getNodes();

// console.log(nodes);

// console.log(graph.hasNode(2));

// console.log(graph.hasEdge(1, 2));

// console.log(graph.getNeighbors(2));
