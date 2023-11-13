const { Graph } = require('bindings')('graph.node');

const graph = new Graph();
graph.addNode(1);
graph.addNode(2);
graph.addEdge(1, 2);

console.log('Has node 1:', graph.hasNode(1)); // Deve imprimir true
console.log('Has edge 1 -> 2:', graph.hasEdge(1, 2)); // Deve imprimir true
