const addon = require('bindings')('graph.node');

export interface IGraph {
  addNode(node: number): void;
  addEdge(node1: number, node2: number): void;
  hasNode(node: number): boolean;
  hasEdge(node1: number, node2: number): boolean;
  getNeighbors(node: number): number[];
  getNodes(): number[];
  toString(): string;
  getInNeighbors(node: number): number[];
  removeNode(node: number): void;
  removeEdge(node1: number, node2: number): void;
}

export var Graph: {
  new(): IGraph
} = addon.Graph;