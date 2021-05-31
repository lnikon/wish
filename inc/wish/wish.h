#ifndef WISH_H
#define WISH_H

#include <string>
#include <vector>
#include <optional>

enum class LogLevel {
	Info,
	Warning,
	Error,
	Debug,

	SizeOfEnum
};

std::string ToString(const LogLevel logLevel);

char** Tokenize(const std::string& str, const std::string& sep);

class Wish
{
	public:
		void Run() const;

	private:
		std::vector<char*> parse(std::string cmdLine) const;
		bool run(const int argc, char** argv) const;
};

#endif // WISH_H
