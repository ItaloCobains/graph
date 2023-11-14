import { Graph, IGraph } from '../graph';


describe('Graph Library', () => {
  let graph: IGraph;

  beforeEach(() => {
    // Cria uma nova instância do Graph antes de cada teste
    graph = new Graph();
  });

  test('should add nodes and edges', () => {
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    expect(graph.hasNode(1)).toBe(true);
    expect(graph.hasNode(2)).toBe(true);
    expect(graph.hasNode(3)).toBe(true);
    expect(graph.hasEdge(1, 2)).toBe(true);
    expect(graph.hasEdge(2, 3)).toBe(true);
  });

  test('should not add duplicate nodes or edges', () => {
    graph.addNode(1);
    graph.addEdge(1, 2);

    // Tentar adicionar nó ou aresta duplicada não deve alterar o estado do grafo
    graph.addNode(1);
    graph.addEdge(1, 2);

    expect(graph.hasNode(1)).toBe(true);
    expect(graph.hasEdge(1, 2)).toBe(true);
  });

  test('should check existence of nodes and edges', () => {
    graph.addNode(1);
    graph.addNode(2);
    graph.addEdge(1, 2);

    expect(graph.hasNode(1)).toBe(true);
    expect(graph.hasNode(3)).toBe(false);
    expect(graph.hasEdge(1, 2)).toBe(true);
    expect(graph.hasEdge(2, 1)).toBe(false);
  });

  test('should return false for non-existent nodes and edges', () => {
    expect(graph.hasNode(1)).toBe(false);
    expect(graph.hasEdge(1, 2)).toBe(false);
  });

  test('should release memory after removing nodes and edges', () => {
    graph.addNode(1);
    graph.addNode(2);
    graph.addEdge(1, 2);

    graph.removeNode(1);
    graph.removeEdge(2, 1);

    expect(graph.hasNode(1)).toBe(false);
    expect(graph.hasNode(2)).toBe(true);
    expect(graph.hasEdge(1, 2)).toBe(false);
    expect(graph.hasEdge(2, 1)).toBe(false);
  });

  test('should return neighbors of nodes', () => {
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    expect(graph.getNeighbors(1)).toEqual([2]);
    expect(graph.getNeighbors(2)).toEqual([3]);
    expect(graph.getNeighbors(3)).toEqual([]);
  });

  test('should return in neighbors of nodes', () => {
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    expect(graph.getInNeighbors(1)).toEqual([]);
    expect(graph.getInNeighbors(2)).toEqual([1]);
    expect(graph.getInNeighbors(3)).toEqual([2]);
  });

  test('should return all nodes', () => {
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);

    expect(graph.getNodes()).toEqual([1, 2, 3]);
  });

  test('should return empty array for neighbors of non-existent nodes', () => {
    expect(graph.getNeighbors(1)).toEqual([]);
  });

  test('should return empty array for in neighbors of non-existent nodes', () => {
    expect(graph.getInNeighbors(1)).toEqual([]);
  });

  test('should return empty array for all nodes of empty graph', () => {
    expect(graph.getNodes()).toEqual([]);
  });

  test('should return empty string for empty graph', () => {
    expect(graph.toString()).toEqual('');
  });

  test('should return string representation of graph', () => {
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    expect(graph.toString()).toEqual('1 -> 2 \n2 -> 3 \n3 -> \n');
  });

  test('should return empty array for nodes of empty graph', () => {
    expect(graph.getNodes()).toEqual([]);
  });
});