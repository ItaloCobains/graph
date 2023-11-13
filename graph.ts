const addon = require('bindings')('graph.node');

export interface IGraph {
  addNode(node: number): void;
  addEdge(node1: number, node2: number): void;
  hasNode(node: number): boolean;
  hasEdge(node1: number, node2: number): boolean;
}

export var Graph: {
  new(): IGraph
} = addon.Graph;