# Graph

Is a lib wirte in c++ and nodejs to manipulate graph more fast.

## Install

```bash
npm i @italocobains/graph
```

## Use

```js
const Graph = require("@italocobains/graph");

const graph = new Graph();
graph.addNode(1);
graph.addNode(2);
graph.addEdge(1, 2);

console.log("Has node 1:", graph.hasNode(1));
console.log("Has edge 1 -> 2:", graph.hasEdge(1, 2));
```
