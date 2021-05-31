#include "wish/wish.h"

#include <iostream>
#include <sstream>

#include <cstdlib>
#include <cstring>
#include <memory>
#include <unistd.h>

#include <sys/wait.h>

#define LOG_OFF

std::string ToString(const LogLevel logLevel) {
  switch (logLevel) {
  case LogLevel::Info:
    return std::string{"Wish Info: "};
    break;
  case LogLevel::Warning:
    return std::string{"Wish Warning: "};
    break;
  case LogLevel::Error:
    return std::string{"Wish Error: "};
    break;
  case LogLevel::Debug:
    return std::string{"Wish Debug: "};
    break;
  default:
    break;
  }

  return std::string{};
}

template <typename... Msgs> void log(const LogLevel logLevel, Msgs... msgs) {
#ifndef LOG_OFF
  std::cout << ToString(logLevel);
  (std::cout << ... << msgs);
#endif
}

std::vector<char *> Tokenize(const std::string &str, char sep) {
  std::vector<char *> args;
  std::istringstream iss(str);

  std::string token;
  while (iss >> token) {
    char *arg = new char[token.size() + 1];
    std::copy(token.begin(), token.end(), arg);
    arg[token.size()] = '\0';
    args.push_back(arg);
  }
  args.push_back(0);
  return args;
}

void Wish::Run() const {
  std::cout << "wish> ";

  std::string cmdLine;
  std::getline(std::cin, cmdLine);

  std::vector<char *> args {parse(cmdLine)};

  if (!run(args.size(), &args[0])) {
    return;
  }
}

std::vector<char*> Wish::parse(std::string cmdLine) const {
	return Tokenize(cmdLine, ' ');
}

bool Wish::run(int argc, char** argv) const {
  // Parse the command and its arguments.

  // Execute the command.
  const int fork_rc = fork();
  if (fork_rc < 0) {
    log(LogLevel::Warning, "Unable to fork: ", argv[0]);
    return false;
  } else if (fork_rc == 0) {
    log(LogLevel::Info, "Successfully forked: ", argv[0]);
	execvp(argv[0], argv);
    return true;
  } else {
    log(LogLevel::Info, "In parent after fork");
    const int wait_rc = wait(NULL);
	for (int argIdx {0}; argIdx < argc; ++argIdx) {
		delete[] argv[argIdx];
	}
    return true;
  }

  return true;
}
