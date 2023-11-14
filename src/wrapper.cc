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
                                                      InstanceMethod("getNeighbors", &GraphWrapper::getNeighbors),
                                                      InstanceMethod("getNodes", &GraphWrapper::getNodes),
                                                      InstanceMethod("toString", &GraphWrapper::toString),
                                                      InstanceMethod("getInNeighbors", &GraphWrapper::getInNeighbors),
                                                      InstanceMethod("removeNode", &GraphWrapper::removeNode),
                                                      InstanceMethod("removeEdge", &GraphWrapper::removeEdge),
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

Napi::Value GraphWrapper::getNeighbors(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  int nodeId = info[0].ToNumber().Int32Value();
  std::vector<int> neighboard = this->graph->getNeighbors(nodeId);
  Napi::Array result = Napi::Array::New(env, neighboard.size());
  for (int i = 0; i < neighboard.size(); i++)
  {
    result[i] = neighboard[i];
  }
  return result;
}

Napi::Value GraphWrapper::getNodes(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  std::vector<int> nodes = this->graph->getNodes();
  Napi::Array result = Napi::Array::New(env, nodes.size());
  for (int i = 0; i < nodes.size(); i++)
  {
    result[i] = nodes[i];
  }
  return result;
}

Napi::Value GraphWrapper::toString(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  std::string result = this->graph->toString();
  return Napi::String::New(env, result);
}

Napi::Value GraphWrapper::getInNeighbors(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  int nodeId = info[0].ToNumber().Int32Value();
  std::vector<int> neighboard = this->graph->getInNeighbors(nodeId);
  Napi::Array result = Napi::Array::New(env, neighboard.size());
  for (int i = 0; i < neighboard.size(); i++)
  {
    result[i] = neighboard[i];
  }
  return result;
}

Napi::Value GraphWrapper::removeNode(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  int nodeId = info[0].ToNumber().Int32Value();
  this->graph->removeNode(nodeId);
  return env.Null();
}

Napi::Value GraphWrapper::removeEdge(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  int from = info[0].ToNumber().Int32Value();
  int to = info[1].ToNumber().Int32Value();
  this->graph->removeEdge(from, to);
  return env.Null();
}