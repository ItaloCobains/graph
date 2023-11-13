#ifndef WRAPPER_HPP
#define WRAPPER_HPP

#include <node-addon-api/napi.h>
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
  Graph *graph;
};

#endif