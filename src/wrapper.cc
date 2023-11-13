#include "wrapper.hpp"

Napi::FunctionReference GraphWrapper::constructor;

Napi::Object GraphWrapper::Init(Napi::Env env, Napi::Object exports)
{
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Graph", {
                                                      InstanceMethod("addNode", &GraphWrapper::AddNode),
                                                      InstanceMethod("addEdge", &GraphWrapper::AddEdge),
                                                      InstanceMethod("hasNode", &GraphWrapper::HasNode),
                                                      InstanceMethod("hasEdge", &GraphWrapper::HasEdge),
                                                  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Graph", func);
  return exports;
}

GraphWrapper::GraphWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<GraphWrapper>(info)
{
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->graph = new Graph();
}

Napi::Value GraphWrapper::AddNode(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  int nodeId = info[0].ToNumber().Int32Value();
  this->graph->addNode(nodeId);
  return env.Null();
}

Napi::Value GraphWrapper::AddEdge(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  int from = info[0].ToNumber().Int32Value();
  int to = info[1].ToNumber().Int32Value();
  this->graph->addEdge(from, to);
  return env.Null();
}

Napi::Value GraphWrapper::HasNode(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  int nodeId = info[0].ToNumber().Int32Value();
  bool hasNode = this->graph->hasNode(nodeId);
  return Napi::Boolean::New(env, hasNode);
}

Napi::Value GraphWrapper::HasEdge(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  int from = info[0].ToNumber().Int32Value();
  int to = info[1].ToNumber().Int32Value();
  bool hasEdge = this->graph->hasEdge(from, to);
  return Napi::Boolean::New(env, hasEdge);
}

