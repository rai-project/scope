#ifdef ENABLE_LAYER_CUDNN_POOLING_FWD
namespace LAYER_CUDNN_POOLING_FWD__1644058051260114996 {

#define BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARGS() \
  Args({{ \
      1 /* Input0 */, \
      256 /* Input1 */, \
      26 /* Input2 */, \
      26 /* Input3 */, \
      3 /* FilterHeight */, \
      3 /* FilterWidth */, \
      0 /* PadHeight */, \
      0 /* PadWidth */, \
      2 /* StrideHeight */, \
      2 /* StrideWidth */, \
  }})

#define BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARG_NAMES() \
  ArgNames({"input[0]", "input[1]", "input[2]", "input[3]", "filter_height", "filter_width", "pad_height", "pad_width", "stride_height", "stride_width"})

static void BENCHMARK_LAYER_CUDNN_POOLING_FWD_ADD_COUNTERS__1644058051260114996(benchmark::State& state) {
  state.counters.insert({
      {"input[0]", 1} /* Input0 */, 
      {"input[1]", 256} /* Input1 */, 
      {"input[2]", 26} /* Input2 */, 
      {"input[3]", 26} /* Input3 */, 
      {"filter_height", 3} /* FilterHeight */, 
      {"filter_width", 3} /* FilterWidth */, 
      {"pad_height", 0} /* PadHeight */, 
      {"pad_width", 0} /* PadWidth */, 
      {"stride_height", 2} /* StrideHeight */, 
      {"stride_width", 2} /* StrideWidth */, 
  });
}

  
  template <cudnnPoolingMode_t pooling_mode>
  static void LAYER_CUDNN_POOLING_FWD_FLOAT32__1644058051260114996(benchmark::State& state) {
    LAYER_CUDNN_POOLING_FWD_Impl<float, pooling_mode>(state);
    BENCHMARK_LAYER_CUDNN_POOLING_FWD_ADD_COUNTERS__1644058051260114996(state);
  }
  
#define BENCHMARK_LAYER_CUDNN_POOLING_FWD(b) \
 BENCHMARK_TEMPLATE(b, CUDNN_POOLING_MAX)-> \
  BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_POOLING_MAX_DETERMINISTIC)-> \
  BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARGS()->\
  UseManualTime(); \


BENCHMARK_LAYER_CUDNN_POOLING_FWD(LAYER_CUDNN_POOLING_FWD_FLOAT32__1644058051260114996);

#undef BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARGS
#undef BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARG_NAMES
#undef BENCHMARK_LAYER_CUDNN_POOLING_FWD
}
#endif // ENABLE_LAYER_CUDNN_POOLING_FWD
#ifdef ENABLE_LAYER_CUDNN_SOFTMAX_FWD
namespace LAYER_CUDNN_SOFTMAX_FWD__17237527966425954981 {

#define BENCHMARK_LAYER_CUDNN_SOFTMAX_FWD_INPUT_ARGS() \
  Args({{ \
      1 /* Input0 */, \
      1000 /* Input1 */, \
      -1 /* Input2 */, \
      -1 /* Input3 */, \
      -1 /* Input4 */, \
      -1 /* Input5 */, \
      -1 /* Input6 */, \
      -1 /* Input7 */, \
  }})

#define BENCHMARK_LAYER_CUDNN_SOFTMAX_FWD_INPUT_ARG_NAMES() \
  ArgNames({"input[0]", "input[1]", "input[2]", "input[3]", "input[4]", "input[5]", "input[6]", "input[7]"})

static void BENCHMARK_LAYER_CUDNN_SOFTMAX_FWD_ADD_COUNTERS__17237527966425954981(benchmark::State& state) {
  state.counters.insert({
      {"input[0]", 1} /* Input0 */, 
      {"input[1]", 1000} /* Input1 */, 
      {"input[2]", -1} /* Input2 */, 
      {"input[3]", -1} /* Input3 */, 
      {"input[4]", -1} /* Input4 */, 
      {"input[5]", -1} /* Input5 */, 
      {"input[6]", -1} /* Input6 */, 
      {"input[7]", -1} /* Input7 */, 
  });
}


template <cudnnSoftmaxAlgorithm_t softmax_algorithm, cudnnSoftmaxMode_t softmax_mode>
static void LAYER_CUDNN_SOFTMAX_FWD_FLOAT32__17237527966425954981(benchmark::State& state) {
  LAYER_CUDNN_SOFTMAX_FWD_Impl<float, softmax_algorithm, softmax_mode>(state);
  BENCHMARK_LAYER_CUDNN_SOFTMAX_FWD_ADD_COUNTERS__17237527966425954981(state);
}

#define BENCHMARK_LAYER_CUDNN_SOFTMAX_FWD0(b, SOFTMAX_MODE) \
 BENCHMARK_TEMPLATE(b, SOFTMAX_MODE, CUDNN_SOFTMAX_MODE_INSTANCE)\
  ->BENCHMARK_LAYER_CUDNN_SOFTMAX_FWD_INPUT_ARG_NAMES()\
  ->BENCHMARK_LAYER_CUDNN_SOFTMAX_FWD_INPUT_ARGS()\
  ->UseManualTime(); \
 BENCHMARK_TEMPLATE(b, SOFTMAX_MODE, CUDNN_SOFTMAX_MODE_CHANNEL)\
  ->BENCHMARK_LAYER_CUDNN_SOFTMAX_FWD_INPUT_ARG_NAMES()\
  ->BENCHMARK_LAYER_CUDNN_SOFTMAX_FWD_INPUT_ARGS()\
  ->UseManualTime(); \


#define BENCHMARK_LAYER_CUDNN_SOFTMAX_FWD(b)                                                                                             \
  BENCHMARK_LAYER_CUDNN_SOFTMAX_FWD0(b, CUDNN_SOFTMAX_FAST);                                                                    \
  BENCHMARK_LAYER_CUDNN_SOFTMAX_FWD0(b, CUDNN_SOFTMAX_ACCURATE);                                                                    \
  BENCHMARK_LAYER_CUDNN_SOFTMAX_FWD0(b, CUDNN_SOFTMAX_LOG)

BENCHMARK_LAYER_CUDNN_SOFTMAX_FWD(LAYER_CUDNN_SOFTMAX_FWD_FLOAT32__17237527966425954981);

#undef BENCHMARK_LAYER_CUDNN_SOFTMAX_FWD_INPUT_ARGS
#undef BENCHMARK_LAYER_CUDNN_SOFTMAX_FWD_INPUT_ARG_NAMES
#undef BENCHMARK_LAYER_CUDNN_SOFTMAX_FWD0
#undef BENCHMARK_LAYER_CUDNN_SOFTMAX_FWD
}
#endif // ENABLE_LAYER_CUDNN_SOFTMAX_FWD
#ifdef ENABLE_LAYER_CUDNN_ACTIVATION_FWD
namespace LAYER_CUDNN_ACTIVATION_FWD__3756321889670451996 {

#define BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS() \
  Args({{ \
      1 /* Input0 */, \
      96 /* Input1 */, \
      54 /* Input2 */, \
      54 /* Input3 */, \
      -1 /* Input4 */, \
      -1 /* Input5 */, \
      -1 /* Input6 */, \
      -1 /* Input7 */, \
  }})

#define BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES() \
  ArgNames({"input[0]", "input[1]", "input[2]", "input[3]", "input[4]", "input[5]", "input[6]", "input[7]"})

static void BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_ADD_COUNTERS__3756321889670451996(benchmark::State& state) {
  state.counters.insert({
      {"input[0]", 1} /* Input0 */, 
      {"input[1]", 96} /* Input1 */, 
      {"input[2]", 54} /* Input2 */, 
      {"input[3]", 54} /* Input3 */, 
      {"input[4]", -1} /* Input4 */, 
      {"input[5]", -1} /* Input5 */, 
      {"input[6]", -1} /* Input6 */, 
      {"input[7]", -1} /* Input7 */, 
  });
}


template <cudnnActivationMode_t activation_mode>
static void LAYER_CUDNN_ACTIVATION_FWD_FLOAT32__3756321889670451996(benchmark::State& state) {
  LAYER_CUDNN_ACTIVATION_FWD_Impl<float, activation_mode>(state);
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_ADD_COUNTERS__3756321889670451996(state);
}

#define BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD(b) \
 BENCHMARK_TEMPLATE(b, CUDNN_ACTIVATION_RELU)-> \
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_ACTIVATION_CLIPPED_RELU)-> \
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS()->\
  UseManualTime(); \


BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD(LAYER_CUDNN_ACTIVATION_FWD_FLOAT32__3756321889670451996);

#undef BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS
#undef BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES
#undef BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD
}
#endif // ENABLE_LAYER_CUDNN_ACTIVATION_FWD
#ifdef ENABLE_LAYER_CUDNN_POOLING_FWD
namespace LAYER_CUDNN_POOLING_FWD__13536075120537619722 {

#define BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARGS() \
  Args({{ \
      1 /* Input0 */, \
      256 /* Input1 */, \
      12 /* Input2 */, \
      12 /* Input3 */, \
      3 /* FilterHeight */, \
      3 /* FilterWidth */, \
      0 /* PadHeight */, \
      1 /* PadWidth */, \
      2 /* StrideHeight */, \
      2 /* StrideWidth */, \
  }})

#define BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARG_NAMES() \
  ArgNames({"input[0]", "input[1]", "input[2]", "input[3]", "filter_height", "filter_width", "pad_height", "pad_width", "stride_height", "stride_width"})

static void BENCHMARK_LAYER_CUDNN_POOLING_FWD_ADD_COUNTERS__13536075120537619722(benchmark::State& state) {
  state.counters.insert({
      {"input[0]", 1} /* Input0 */, 
      {"input[1]", 256} /* Input1 */, 
      {"input[2]", 12} /* Input2 */, 
      {"input[3]", 12} /* Input3 */, 
      {"filter_height", 3} /* FilterHeight */, 
      {"filter_width", 3} /* FilterWidth */, 
      {"pad_height", 0} /* PadHeight */, 
      {"pad_width", 1} /* PadWidth */, 
      {"stride_height", 2} /* StrideHeight */, 
      {"stride_width", 2} /* StrideWidth */, 
  });
}

  
  template <cudnnPoolingMode_t pooling_mode>
  static void LAYER_CUDNN_POOLING_FWD_FLOAT32__13536075120537619722(benchmark::State& state) {
    LAYER_CUDNN_POOLING_FWD_Impl<float, pooling_mode>(state);
    BENCHMARK_LAYER_CUDNN_POOLING_FWD_ADD_COUNTERS__13536075120537619722(state);
  }
  
#define BENCHMARK_LAYER_CUDNN_POOLING_FWD(b) \
 BENCHMARK_TEMPLATE(b, CUDNN_POOLING_MAX)-> \
  BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_POOLING_MAX_DETERMINISTIC)-> \
  BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARGS()->\
  UseManualTime(); \


BENCHMARK_LAYER_CUDNN_POOLING_FWD(LAYER_CUDNN_POOLING_FWD_FLOAT32__13536075120537619722);

#undef BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARGS
#undef BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARG_NAMES
#undef BENCHMARK_LAYER_CUDNN_POOLING_FWD
}
#endif // ENABLE_LAYER_CUDNN_POOLING_FWD
#ifdef ENABLE_LAYER_CUDNN_ACTIVATION_FWD
namespace LAYER_CUDNN_ACTIVATION_FWD__17930685256344347291 {

#define BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS() \
  Args({{ \
      1 /* Input0 */, \
      384 /* Input1 */, \
      12 /* Input2 */, \
      12 /* Input3 */, \
      -1 /* Input4 */, \
      -1 /* Input5 */, \
      -1 /* Input6 */, \
      -1 /* Input7 */, \
  }})

#define BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES() \
  ArgNames({"input[0]", "input[1]", "input[2]", "input[3]", "input[4]", "input[5]", "input[6]", "input[7]"})

static void BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_ADD_COUNTERS__17930685256344347291(benchmark::State& state) {
  state.counters.insert({
      {"input[0]", 1} /* Input0 */, 
      {"input[1]", 384} /* Input1 */, 
      {"input[2]", 12} /* Input2 */, 
      {"input[3]", 12} /* Input3 */, 
      {"input[4]", -1} /* Input4 */, 
      {"input[5]", -1} /* Input5 */, 
      {"input[6]", -1} /* Input6 */, 
      {"input[7]", -1} /* Input7 */, 
  });
}


template <cudnnActivationMode_t activation_mode>
static void LAYER_CUDNN_ACTIVATION_FWD_FLOAT32__17930685256344347291(benchmark::State& state) {
  LAYER_CUDNN_ACTIVATION_FWD_Impl<float, activation_mode>(state);
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_ADD_COUNTERS__17930685256344347291(state);
}

#define BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD(b) \
 BENCHMARK_TEMPLATE(b, CUDNN_ACTIVATION_RELU)-> \
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_ACTIVATION_CLIPPED_RELU)-> \
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS()->\
  UseManualTime(); \


BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD(LAYER_CUDNN_ACTIVATION_FWD_FLOAT32__17930685256344347291);

#undef BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS
#undef BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES
#undef BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD
}
#endif // ENABLE_LAYER_CUDNN_ACTIVATION_FWD
#ifdef ENABLE_LAYER_CUDNN_ACTIVATION_FWD
namespace LAYER_CUDNN_ACTIVATION_FWD__6991840624476787281 {

#define BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS() \
  Args({{ \
      1 /* Input0 */, \
      256 /* Input1 */, \
      12 /* Input2 */, \
      12 /* Input3 */, \
      -1 /* Input4 */, \
      -1 /* Input5 */, \
      -1 /* Input6 */, \
      -1 /* Input7 */, \
  }})

#define BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES() \
  ArgNames({"input[0]", "input[1]", "input[2]", "input[3]", "input[4]", "input[5]", "input[6]", "input[7]"})

static void BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_ADD_COUNTERS__6991840624476787281(benchmark::State& state) {
  state.counters.insert({
      {"input[0]", 1} /* Input0 */, 
      {"input[1]", 256} /* Input1 */, 
      {"input[2]", 12} /* Input2 */, 
      {"input[3]", 12} /* Input3 */, 
      {"input[4]", -1} /* Input4 */, 
      {"input[5]", -1} /* Input5 */, 
      {"input[6]", -1} /* Input6 */, 
      {"input[7]", -1} /* Input7 */, 
  });
}


template <cudnnActivationMode_t activation_mode>
static void LAYER_CUDNN_ACTIVATION_FWD_FLOAT32__6991840624476787281(benchmark::State& state) {
  LAYER_CUDNN_ACTIVATION_FWD_Impl<float, activation_mode>(state);
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_ADD_COUNTERS__6991840624476787281(state);
}

#define BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD(b) \
 BENCHMARK_TEMPLATE(b, CUDNN_ACTIVATION_RELU)-> \
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_ACTIVATION_CLIPPED_RELU)-> \
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS()->\
  UseManualTime(); \


BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD(LAYER_CUDNN_ACTIVATION_FWD_FLOAT32__6991840624476787281);

#undef BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS
#undef BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES
#undef BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD
}
#endif // ENABLE_LAYER_CUDNN_ACTIVATION_FWD
#ifdef ENABLE_LAYER_CUDNN_CONV_FWD
namespace LAYER_CUDNN_CONV_FWD__13042571298903103087 {

#define BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS() \
  Args({{ \
      1 /* Input0 */, \
      256 /* Input1 */, \
      12 /* Input2 */, \
      12 /* Input3 */, \
      384 /* FilterCount */, \
      3 /* FilterHeight */, \
      3 /* FilterWidth */, \
      1 /* PadHeight */, \
      1 /* PadWidth */, \
      1 /* StrideHeight */, \
      1 /* StrideWidth */, \
      1 /* DilationWidth */, \
      1 /* DilationHeight */, \
  }})

#define BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES() \
  ArgNames({"input[0]", "input[1]", "input[2]", "input[3]", "filter_count", "filter_height", "filter_width", "pad_height", "pad_width", "stride_height", "stride_width", "dilation_height", "dilation_width"})

static void BENCHMARK_LAYER_CUDNN_CONV_FWD_ADD_COUNTERS__13042571298903103087(benchmark::State& state) {
  state.counters.insert({
      {"input[0]", 1} /* Input0 */, 
      {"input[1]", 256} /* Input1 */, 
      {"input[2]", 12} /* Input2 */, 
      {"input[3]", 12} /* Input3 */, 
      {"filter_count", 384} /* FilterCount */, 
      {"filter_height", 3} /* FilterHeight */, 
      {"filter_width", 3} /* FilterWidth */, 
      {"pad_height", 1} /* PadHeight */, 
      {"pad_width", 1} /* PadWidth */, 
      {"stride_height", 1} /* StrideHeight */, 
      {"stride_width", 1} /* StrideWidth */, 
      {"dilation_height", 1} /* DilationWidth */, 
      {"dilation_width", 1} /* DilationHeight */, 
  });
}

  
  template <cudnnConvolutionFwdAlgo_t convolution_algorithm>
  static void LAYER_CUDNN_CONV_FWD_FLOAT32__13042571298903103087(benchmark::State& state) {
    
      LAYER_CUDNN_CONV_FWD_Impl<float, convolution_algorithm>(state);
    
    BENCHMARK_LAYER_CUDNN_CONV_FWD_ADD_COUNTERS__13042571298903103087(state);
  }
  

#define BENCHMARK_LAYER_CUDNN_CONV_FWD(b) \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_IMPLICIT_GEMM)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_IMPLICIT_PRECOMP_GEMM)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_GEMM)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_DIRECT)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_FFT)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_FFT_TILING)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_WINOGRAD)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_WINOGRAD_NONFUSED)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \


BENCHMARK_LAYER_CUDNN_CONV_FWD(LAYER_CUDNN_CONV_FWD_FLOAT32__13042571298903103087);

#undef BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS
#undef BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES
#undef BENCHMARK_LAYER_CUDNN_CONV_FWD
}
#endif // ENABLE_LAYER_CUDNN_CONV_FWD
#ifdef ENABLE_LAYER_CUDNN_ACTIVATION_FWD
namespace LAYER_CUDNN_ACTIVATION_FWD__15417294399166253268 {

#define BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS() \
  Args({{ \
      1 /* Input0 */, \
      256 /* Input1 */, \
      26 /* Input2 */, \
      26 /* Input3 */, \
      -1 /* Input4 */, \
      -1 /* Input5 */, \
      -1 /* Input6 */, \
      -1 /* Input7 */, \
  }})

#define BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES() \
  ArgNames({"input[0]", "input[1]", "input[2]", "input[3]", "input[4]", "input[5]", "input[6]", "input[7]"})

static void BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_ADD_COUNTERS__15417294399166253268(benchmark::State& state) {
  state.counters.insert({
      {"input[0]", 1} /* Input0 */, 
      {"input[1]", 256} /* Input1 */, 
      {"input[2]", 26} /* Input2 */, 
      {"input[3]", 26} /* Input3 */, 
      {"input[4]", -1} /* Input4 */, 
      {"input[5]", -1} /* Input5 */, 
      {"input[6]", -1} /* Input6 */, 
      {"input[7]", -1} /* Input7 */, 
  });
}


template <cudnnActivationMode_t activation_mode>
static void LAYER_CUDNN_ACTIVATION_FWD_FLOAT32__15417294399166253268(benchmark::State& state) {
  LAYER_CUDNN_ACTIVATION_FWD_Impl<float, activation_mode>(state);
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_ADD_COUNTERS__15417294399166253268(state);
}

#define BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD(b) \
 BENCHMARK_TEMPLATE(b, CUDNN_ACTIVATION_RELU)-> \
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_ACTIVATION_CLIPPED_RELU)-> \
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS()->\
  UseManualTime(); \


BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD(LAYER_CUDNN_ACTIVATION_FWD_FLOAT32__15417294399166253268);

#undef BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS
#undef BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES
#undef BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD
}
#endif // ENABLE_LAYER_CUDNN_ACTIVATION_FWD
#ifdef ENABLE_LAYER_CUDNN_CONV_FWD
namespace LAYER_CUDNN_CONV_FWD__1753043122443293887 {

#define BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS() \
  Args({{ \
      1 /* Input0 */, \
      96 /* Input1 */, \
      26 /* Input2 */, \
      26 /* Input3 */, \
      256 /* FilterCount */, \
      5 /* FilterHeight */, \
      5 /* FilterWidth */, \
      2 /* PadHeight */, \
      2 /* PadWidth */, \
      1 /* StrideHeight */, \
      1 /* StrideWidth */, \
      1 /* DilationWidth */, \
      1 /* DilationHeight */, \
  }})

#define BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES() \
  ArgNames({"input[0]", "input[1]", "input[2]", "input[3]", "filter_count", "filter_height", "filter_width", "pad_height", "pad_width", "stride_height", "stride_width", "dilation_height", "dilation_width"})

static void BENCHMARK_LAYER_CUDNN_CONV_FWD_ADD_COUNTERS__1753043122443293887(benchmark::State& state) {
  state.counters.insert({
      {"input[0]", 1} /* Input0 */, 
      {"input[1]", 96} /* Input1 */, 
      {"input[2]", 26} /* Input2 */, 
      {"input[3]", 26} /* Input3 */, 
      {"filter_count", 256} /* FilterCount */, 
      {"filter_height", 5} /* FilterHeight */, 
      {"filter_width", 5} /* FilterWidth */, 
      {"pad_height", 2} /* PadHeight */, 
      {"pad_width", 2} /* PadWidth */, 
      {"stride_height", 1} /* StrideHeight */, 
      {"stride_width", 1} /* StrideWidth */, 
      {"dilation_height", 1} /* DilationWidth */, 
      {"dilation_width", 1} /* DilationHeight */, 
  });
}

  
  template <cudnnConvolutionFwdAlgo_t convolution_algorithm>
  static void LAYER_CUDNN_CONV_FWD_FLOAT32__1753043122443293887(benchmark::State& state) {
    
      LAYER_CUDNN_CONV_FWD_Impl<float, convolution_algorithm>(state);
    
    BENCHMARK_LAYER_CUDNN_CONV_FWD_ADD_COUNTERS__1753043122443293887(state);
  }
  

#define BENCHMARK_LAYER_CUDNN_CONV_FWD(b) \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_IMPLICIT_GEMM)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_IMPLICIT_PRECOMP_GEMM)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_GEMM)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_DIRECT)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_FFT)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_FFT_TILING)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_WINOGRAD)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_WINOGRAD_NONFUSED)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \


BENCHMARK_LAYER_CUDNN_CONV_FWD(LAYER_CUDNN_CONV_FWD_FLOAT32__1753043122443293887);

#undef BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS
#undef BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES
#undef BENCHMARK_LAYER_CUDNN_CONV_FWD
}
#endif // ENABLE_LAYER_CUDNN_CONV_FWD
#ifdef ENABLE_LAYER_CUDNN_POOLING_FWD
namespace LAYER_CUDNN_POOLING_FWD__4513027207653764788 {

#define BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARGS() \
  Args({{ \
      1 /* Input0 */, \
      96 /* Input1 */, \
      54 /* Input2 */, \
      54 /* Input3 */, \
      3 /* FilterHeight */, \
      3 /* FilterWidth */, \
      0 /* PadHeight */, \
      0 /* PadWidth */, \
      2 /* StrideHeight */, \
      2 /* StrideWidth */, \
  }})

#define BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARG_NAMES() \
  ArgNames({"input[0]", "input[1]", "input[2]", "input[3]", "filter_height", "filter_width", "pad_height", "pad_width", "stride_height", "stride_width"})

static void BENCHMARK_LAYER_CUDNN_POOLING_FWD_ADD_COUNTERS__4513027207653764788(benchmark::State& state) {
  state.counters.insert({
      {"input[0]", 1} /* Input0 */, 
      {"input[1]", 96} /* Input1 */, 
      {"input[2]", 54} /* Input2 */, 
      {"input[3]", 54} /* Input3 */, 
      {"filter_height", 3} /* FilterHeight */, 
      {"filter_width", 3} /* FilterWidth */, 
      {"pad_height", 0} /* PadHeight */, 
      {"pad_width", 0} /* PadWidth */, 
      {"stride_height", 2} /* StrideHeight */, 
      {"stride_width", 2} /* StrideWidth */, 
  });
}

  
  template <cudnnPoolingMode_t pooling_mode>
  static void LAYER_CUDNN_POOLING_FWD_FLOAT32__4513027207653764788(benchmark::State& state) {
    LAYER_CUDNN_POOLING_FWD_Impl<float, pooling_mode>(state);
    BENCHMARK_LAYER_CUDNN_POOLING_FWD_ADD_COUNTERS__4513027207653764788(state);
  }
  
#define BENCHMARK_LAYER_CUDNN_POOLING_FWD(b) \
 BENCHMARK_TEMPLATE(b, CUDNN_POOLING_MAX)-> \
  BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_POOLING_MAX_DETERMINISTIC)-> \
  BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARGS()->\
  UseManualTime(); \


BENCHMARK_LAYER_CUDNN_POOLING_FWD(LAYER_CUDNN_POOLING_FWD_FLOAT32__4513027207653764788);

#undef BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARGS
#undef BENCHMARK_LAYER_CUDNN_POOLING_FWD_INPUT_ARG_NAMES
#undef BENCHMARK_LAYER_CUDNN_POOLING_FWD
}
#endif // ENABLE_LAYER_CUDNN_POOLING_FWD
#ifdef ENABLE_LAYER_CUDNN_ACTIVATION_FWD
namespace LAYER_CUDNN_ACTIVATION_FWD__14263831019593457275 {

#define BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS() \
  Args({{ \
      1 /* Input0 */, \
      4096 /* Input1 */, \
      -1 /* Input2 */, \
      -1 /* Input3 */, \
      -1 /* Input4 */, \
      -1 /* Input5 */, \
      -1 /* Input6 */, \
      -1 /* Input7 */, \
  }})

#define BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES() \
  ArgNames({"input[0]", "input[1]", "input[2]", "input[3]", "input[4]", "input[5]", "input[6]", "input[7]"})

static void BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_ADD_COUNTERS__14263831019593457275(benchmark::State& state) {
  state.counters.insert({
      {"input[0]", 1} /* Input0 */, 
      {"input[1]", 4096} /* Input1 */, 
      {"input[2]", -1} /* Input2 */, 
      {"input[3]", -1} /* Input3 */, 
      {"input[4]", -1} /* Input4 */, 
      {"input[5]", -1} /* Input5 */, 
      {"input[6]", -1} /* Input6 */, 
      {"input[7]", -1} /* Input7 */, 
  });
}


template <cudnnActivationMode_t activation_mode>
static void LAYER_CUDNN_ACTIVATION_FWD_FLOAT32__14263831019593457275(benchmark::State& state) {
  LAYER_CUDNN_ACTIVATION_FWD_Impl<float, activation_mode>(state);
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_ADD_COUNTERS__14263831019593457275(state);
}

#define BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD(b) \
 BENCHMARK_TEMPLATE(b, CUDNN_ACTIVATION_RELU)-> \
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_ACTIVATION_CLIPPED_RELU)-> \
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS()->\
  UseManualTime(); \


BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD(LAYER_CUDNN_ACTIVATION_FWD_FLOAT32__14263831019593457275);

#undef BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARGS
#undef BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD_INPUT_ARG_NAMES
#undef BENCHMARK_LAYER_CUDNN_ACTIVATION_FWD
}
#endif // ENABLE_LAYER_CUDNN_ACTIVATION_FWD
#ifdef ENABLE_LAYER_CUDNN_CONV_FWD
namespace LAYER_CUDNN_CONV_FWD__4863986124195955951 {

#define BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS() \
  Args({{ \
      1 /* Input0 */, \
      384 /* Input1 */, \
      12 /* Input2 */, \
      12 /* Input3 */, \
      256 /* FilterCount */, \
      3 /* FilterHeight */, \
      3 /* FilterWidth */, \
      1 /* PadHeight */, \
      1 /* PadWidth */, \
      1 /* StrideHeight */, \
      1 /* StrideWidth */, \
      1 /* DilationWidth */, \
      1 /* DilationHeight */, \
  }})

#define BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES() \
  ArgNames({"input[0]", "input[1]", "input[2]", "input[3]", "filter_count", "filter_height", "filter_width", "pad_height", "pad_width", "stride_height", "stride_width", "dilation_height", "dilation_width"})

static void BENCHMARK_LAYER_CUDNN_CONV_FWD_ADD_COUNTERS__4863986124195955951(benchmark::State& state) {
  state.counters.insert({
      {"input[0]", 1} /* Input0 */, 
      {"input[1]", 384} /* Input1 */, 
      {"input[2]", 12} /* Input2 */, 
      {"input[3]", 12} /* Input3 */, 
      {"filter_count", 256} /* FilterCount */, 
      {"filter_height", 3} /* FilterHeight */, 
      {"filter_width", 3} /* FilterWidth */, 
      {"pad_height", 1} /* PadHeight */, 
      {"pad_width", 1} /* PadWidth */, 
      {"stride_height", 1} /* StrideHeight */, 
      {"stride_width", 1} /* StrideWidth */, 
      {"dilation_height", 1} /* DilationWidth */, 
      {"dilation_width", 1} /* DilationHeight */, 
  });
}

  
  template <cudnnConvolutionFwdAlgo_t convolution_algorithm>
  static void LAYER_CUDNN_CONV_FWD_FLOAT32__4863986124195955951(benchmark::State& state) {
    
      LAYER_CUDNN_CONV_FWD_Impl<float, convolution_algorithm>(state);
    
    BENCHMARK_LAYER_CUDNN_CONV_FWD_ADD_COUNTERS__4863986124195955951(state);
  }
  

#define BENCHMARK_LAYER_CUDNN_CONV_FWD(b) \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_IMPLICIT_GEMM)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_IMPLICIT_PRECOMP_GEMM)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_GEMM)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_DIRECT)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_FFT)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_FFT_TILING)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_WINOGRAD)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_WINOGRAD_NONFUSED)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \


BENCHMARK_LAYER_CUDNN_CONV_FWD(LAYER_CUDNN_CONV_FWD_FLOAT32__4863986124195955951);

#undef BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS
#undef BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES
#undef BENCHMARK_LAYER_CUDNN_CONV_FWD
}
#endif // ENABLE_LAYER_CUDNN_CONV_FWD
#ifdef ENABLE_LAYER_CUDNN_DROPOUT_FWD
namespace LAYER_CUDNN_DROPOUT_FWD__9152737467926222237 {

#define BENCHMARK_LAYER_CUDNN_DROPOUT_FWD_INPUT_ARGS() \
  Args({{ \
      1 /* Input0 */, \
      4096 /* Input1 */, \
      -1 /* Input2 */, \
      -1 /* Input3 */, \
      -1 /* Input4 */, \
      -1 /* Input5 */, \
      -1 /* Input6 */, \
      -1 /* Input7 */, \
  }})

#define BENCHMARK_LAYER_CUDNN_DROPOUT_FWD_INPUT_ARG_NAMES() \
  ArgNames({"input[0]", "input[1]", "input[2]", "input[3]", "input[4]", "input[5]", "input[6]", "input[7]"})

static void BENCHMARK_LAYER_CUDNN_DROPOUT_FWD_ADD_COUNTERS__9152737467926222237(benchmark::State& state) {
  state.counters.insert({
      {"input[0]", 1} /* Input0 */, 
      {"input[1]", 4096} /* Input1 */, 
      {"input[2]", -1} /* Input2 */, 
      {"input[3]", -1} /* Input3 */, 
      {"input[4]", -1} /* Input4 */, 
      {"input[5]", -1} /* Input5 */, 
      {"input[6]", -1} /* Input6 */, 
      {"input[7]", -1} /* Input7 */, 
  });
}


static void LAYER_CUDNN_DROPOUT_FWD_FLOAT32__9152737467926222237(benchmark::State& state) {
  LAYER_CUDNN_DROPOUT_FWD_Impl<float>(state);
  BENCHMARK_LAYER_CUDNN_DROPOUT_FWD_ADD_COUNTERS__9152737467926222237(state);
}




BENCHMARK(LAYER_CUDNN_DROPOUT_FWD_FLOAT32__9152737467926222237)->\
  BENCHMARK_LAYER_CUDNN_DROPOUT_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_DROPOUT_FWD_INPUT_ARGS()->\
  UseManualTime();

#undef BENCHMARK_LAYER_CUDNN_DROPOUT_FWD_INPUT_ARGS
#undef BENCHMARK_LAYER_CUDNN_DROPOUT_FWD_INPUT_ARG_NAMES
}
#endif // ENABLE_LAYER_CUDNN_DROPOUT_FWD
#ifdef ENABLE_LAYER_CUDNN_CONV_FWD
namespace LAYER_CUDNN_CONV_FWD__6551901671649110634 {

#define BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS() \
  Args({{ \
      1 /* Input0 */, \
      3 /* Input1 */, \
      224 /* Input2 */, \
      224 /* Input3 */, \
      96 /* FilterCount */, \
      11 /* FilterHeight */, \
      11 /* FilterWidth */, \
      0 /* PadHeight */, \
      0 /* PadWidth */, \
      4 /* StrideHeight */, \
      4 /* StrideWidth */, \
      1 /* DilationWidth */, \
      1 /* DilationHeight */, \
  }})

#define BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES() \
  ArgNames({"input[0]", "input[1]", "input[2]", "input[3]", "filter_count", "filter_height", "filter_width", "pad_height", "pad_width", "stride_height", "stride_width", "dilation_height", "dilation_width"})

static void BENCHMARK_LAYER_CUDNN_CONV_FWD_ADD_COUNTERS__6551901671649110634(benchmark::State& state) {
  state.counters.insert({
      {"input[0]", 1} /* Input0 */, 
      {"input[1]", 3} /* Input1 */, 
      {"input[2]", 224} /* Input2 */, 
      {"input[3]", 224} /* Input3 */, 
      {"filter_count", 96} /* FilterCount */, 
      {"filter_height", 11} /* FilterHeight */, 
      {"filter_width", 11} /* FilterWidth */, 
      {"pad_height", 0} /* PadHeight */, 
      {"pad_width", 0} /* PadWidth */, 
      {"stride_height", 4} /* StrideHeight */, 
      {"stride_width", 4} /* StrideWidth */, 
      {"dilation_height", 1} /* DilationWidth */, 
      {"dilation_width", 1} /* DilationHeight */, 
  });
}

  
  template <cudnnConvolutionFwdAlgo_t convolution_algorithm>
  static void LAYER_CUDNN_CONV_FWD_FLOAT32__6551901671649110634(benchmark::State& state) {
    
      LAYER_CUDNN_CONV_FWD_Impl<float, convolution_algorithm>(state);
    
    BENCHMARK_LAYER_CUDNN_CONV_FWD_ADD_COUNTERS__6551901671649110634(state);
  }
  

#define BENCHMARK_LAYER_CUDNN_CONV_FWD(b) \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_IMPLICIT_GEMM)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_IMPLICIT_PRECOMP_GEMM)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_GEMM)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_DIRECT)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_FFT)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_FFT_TILING)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_WINOGRAD)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_WINOGRAD_NONFUSED)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \


BENCHMARK_LAYER_CUDNN_CONV_FWD(LAYER_CUDNN_CONV_FWD_FLOAT32__6551901671649110634);

#undef BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS
#undef BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES
#undef BENCHMARK_LAYER_CUDNN_CONV_FWD
}
#endif // ENABLE_LAYER_CUDNN_CONV_FWD
#ifdef ENABLE_LAYER_CUDNN_CONV_FWD
namespace LAYER_CUDNN_CONV_FWD__12732263121457752951 {

#define BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS() \
  Args({{ \
      1 /* Input0 */, \
      384 /* Input1 */, \
      12 /* Input2 */, \
      12 /* Input3 */, \
      384 /* FilterCount */, \
      3 /* FilterHeight */, \
      3 /* FilterWidth */, \
      1 /* PadHeight */, \
      1 /* PadWidth */, \
      1 /* StrideHeight */, \
      1 /* StrideWidth */, \
      1 /* DilationWidth */, \
      1 /* DilationHeight */, \
  }})

#define BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES() \
  ArgNames({"input[0]", "input[1]", "input[2]", "input[3]", "filter_count", "filter_height", "filter_width", "pad_height", "pad_width", "stride_height", "stride_width", "dilation_height", "dilation_width"})

static void BENCHMARK_LAYER_CUDNN_CONV_FWD_ADD_COUNTERS__12732263121457752951(benchmark::State& state) {
  state.counters.insert({
      {"input[0]", 1} /* Input0 */, 
      {"input[1]", 384} /* Input1 */, 
      {"input[2]", 12} /* Input2 */, 
      {"input[3]", 12} /* Input3 */, 
      {"filter_count", 384} /* FilterCount */, 
      {"filter_height", 3} /* FilterHeight */, 
      {"filter_width", 3} /* FilterWidth */, 
      {"pad_height", 1} /* PadHeight */, 
      {"pad_width", 1} /* PadWidth */, 
      {"stride_height", 1} /* StrideHeight */, 
      {"stride_width", 1} /* StrideWidth */, 
      {"dilation_height", 1} /* DilationWidth */, 
      {"dilation_width", 1} /* DilationHeight */, 
  });
}

  
  template <cudnnConvolutionFwdAlgo_t convolution_algorithm>
  static void LAYER_CUDNN_CONV_FWD_FLOAT32__12732263121457752951(benchmark::State& state) {
    
      LAYER_CUDNN_CONV_FWD_Impl<float, convolution_algorithm>(state);
    
    BENCHMARK_LAYER_CUDNN_CONV_FWD_ADD_COUNTERS__12732263121457752951(state);
  }
  

#define BENCHMARK_LAYER_CUDNN_CONV_FWD(b) \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_IMPLICIT_GEMM)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_IMPLICIT_PRECOMP_GEMM)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_GEMM)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_DIRECT)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_FFT)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_FFT_TILING)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_WINOGRAD)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \
 BENCHMARK_TEMPLATE(b, CUDNN_CONVOLUTION_FWD_ALGO_WINOGRAD_NONFUSED)-> \
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES()->\
  BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS()->\
  UseManualTime(); \


BENCHMARK_LAYER_CUDNN_CONV_FWD(LAYER_CUDNN_CONV_FWD_FLOAT32__12732263121457752951);

#undef BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARGS
#undef BENCHMARK_LAYER_CUDNN_CONV_FWD_INPUT_ARG_NAMES
#undef BENCHMARK_LAYER_CUDNN_CONV_FWD
}
#endif // ENABLE_LAYER_CUDNN_CONV_FWD
