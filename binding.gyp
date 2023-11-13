{ 
  "targets": [ 
    { 
      "target_name": "graph", 
      "cflags!": [ "-fno-exceptions" ], 
      "cflags_cc!": [ "-fno-exceptions" ], 
      "sources": [ 
        "./src/graph.cpp", 
        "./src/index.cpp" 
      ], 
      "include_dirs": [ 
        "./node_modules/node-addon-api",
      ], 
      'define': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ], 
    } 
  ] 
}