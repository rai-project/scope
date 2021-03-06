#include "scope/init/init.hpp"
#include "scope/init/cuda.hpp"
#include "scope/init/flags.hpp"
#include "scope/init/logger.hpp"

static std::vector<AfterInitRecord> &AfterInits() {
  static std::vector<AfterInitRecord> after_inits;
  return after_inits;
}


static struct { InitFn fn; } inits[5000];
static size_t ninits = 0;

static BeforeInitFn before_inits[5000];
static size_t n_before_inits = 0;

static clara::Parser cli;
static std::vector<std::string> version_strings;

const std::vector<std::string>& VersionStrings() {
  return version_strings;
}

void RegisterOpt(clara::Opt opt) {
  cli = cli | opt;
}


void do_before_inits() {
  for (size_t i = 0; i < n_before_inits; ++i) {
    before_inits[i]();
  }
}

void do_after_inits() {
  LOG(debug, "running {} after init functions", AfterInits().size());
  for (size_t i = 0; i < AfterInits().size(); ++i) {
    auto r = AfterInits()[i];
    LOG(debug, "Calling AfterInit  {} ({})", i, r.name);
    r.fn();
    LOG(trace, "Finished AfterInit {} ({})", i, r.name);
  }
}

void init_flags(int argc, char **argv) {


  // register scope flags first
  register_flags();

  // parse flags
  auto result = cli.parse(clara::Args(argc, argv));
  if (!result) {
    LOG(critical, result.errorMessage());
    exit(-1);
  }

  if (FLAG(help)) {
    std::cout << cli << "\n";
  }

}

void init() {

  init_cuda();

  for (size_t i = 0; i < ninits; ++i) {
    LOG(debug, "Running init function {}", i);
    int status = inits[i].fn();
    if (status) {
      exit(status);
    }
  }
}



void RegisterInit(InitFn fn) {
  if (ninits >= sizeof(inits) / sizeof(inits[0])) {
    LOG(critical, "ERROR: {}@{}: RegisterInit failed, too many inits", __FILE__, __LINE__);
    exit(-1);
  }
  inits[ninits].fn = fn;
  ninits++;
}

void RegisterBeforeInit(BeforeInitFn fn) {
  if (n_before_inits >= sizeof(before_inits) / sizeof(before_inits[0])) {
    LOG(critical, "ERROR: {}@{}: RegisterBeforeInit failed, too many functions", __FILE__, __LINE__);
    exit(-1);
  }
  before_inits[n_before_inits] = fn;
  n_before_inits++;
}

AfterInitFn RegisterAfterInit(AfterInitFn fn, const char *name) {
  AfterInits().push_back({fn, name});
  return fn;
}

void RegisterVersionString(const std::string &s) {
  version_strings.push_back(s);
}
