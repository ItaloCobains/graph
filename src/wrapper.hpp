#ifndef WRAPPER_HPP
#define WRAPPER_HPP

#include <napi.h>
#include "graph.hpp"

class GraphWrapper : public Napi::ObjectWrap<GraphWrapper>
{
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  GraphWrapper(const Napi::CallbackInfo &info);

private:
  static Napi::FunctionReference constructor;
  Napi::Value AddNode(const Napi::CallbackInfo &info);
  Napi::Value AddEdge(const Napi::CallbackInfo &info);
  Napi::Value HasNode(const Napi::CallbackInfo &info);
  Napi::Value HasEdge(const Napi::CallbackInfo &info);
  Napi::Value getNeighbors(const Napi::CallbackInfo &info);
  Napi::Value getNodes(const Napi::CallbackInfo &info);
  Napi::Value toString(const Napi::CallbackInfo &info);
  Napi::Value getInNeighbors(const Napi::CallbackInfo &info);
  Napi::Value removeNode(const Napi::CallbackInfo &info);
  Napi::Value removeEdge(const Napi::CallbackInfo &info);
  Napi::Value getOutNeighbors(const Napi::CallbackInfo &info);
  Napi::Value getEdge(const Napi::CallbackInfo &info);
  Napi::Value getDegree(const Napi::CallbackInfo &info);
  Napi::Value getInDegree(const Napi::CallbackInfo &info);
  Napi::Value getOutDegree(const Napi::CallbackInfo &info);
  Napi::Value isEmpty(const Napi::CallbackInfo &info);
  Napi::Value clear(const Napi::CallbackInfo &info);
  Napi::Value getNumNodes(const Napi::CallbackInfo &info);
  Napi::Value getNumEdges(const Napi::CallbackInfo &info);
  Graph *graph;
};

#endif