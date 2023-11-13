#include <napi.h>
#include "graph.hpp"
#include "wrapper.hpp"

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
  return GraphWrapper::Init(env, exports);
}

NODE_API_MODULE(graph, InitAll)