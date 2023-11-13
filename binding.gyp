{ 
  "targets": [ 
    { 
      "target_name": "graph", 
      "cflags!": [ "-fno-exceptions" ], 
      "cflags_cc!": [ "-fno-exceptions" ], 
      "sources": [ 
        "./src/graph.cc", 
        "./src/index.cc",
        "./src/wrapper.cc",
      ], 
      "include_dirs": [ 
        "./node_modules/node-addon-api",
      ], 
      'define': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ], 
    } 
  ] 
}