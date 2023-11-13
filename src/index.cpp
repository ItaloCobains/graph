#include <napi.h>
#include "graph.h"
#include <string>

Napi::String helloGraph(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  std::string user = (std::string)info[0].ToString();

  std::string result = helloUser(user);

  return Napi::String::New(env, result);
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "helloGraph"),
              Napi::Function::New(env, helloGraph)
              );

  return exports;
}

NODE_API_MODULE(graph, Init)