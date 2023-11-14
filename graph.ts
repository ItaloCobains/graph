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
  getOutNeighbors(node: number): number[];
  getEdge(node1: number, node2: number): number;
  getDegree(node: number): number;
  getInDegree(node: number): number;
  getOutDegree(node: number): number;
  isEmpty(): boolean;
  clear(): void;
  getNumNodes(): number;
  getNumEdges(): number;
}

export var Graph: {
  new(): IGraph
} = addon.Graph;