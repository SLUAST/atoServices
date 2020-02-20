#ifndef LOG_HANDLER_HPP
#define LOG_HANDLER_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <wchar.h>
#include <fstream>
#include <ostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <chrono>  

enum verboseLevel {
	DEBUG = 0,
	INFO = 1,
	WARN = 2,
	ERROR = 3,
	CRITICAL = 4
};

class LogHandler {
private:

	void Initialize();

	std::tm* f_getSystemTime();
	std::string f_getSystemDateFormatted();
	std::string f_getSystemTimeFormatted();

	std::string m_logPath = "/opt/vigil/logs/";
	std::string m_serviceName = "testingService_";
	std::string m_currentLogPath;

	bool m_writeToFile = true;
	bool m_writeToConsole = true;

	bool f_writeToFile(const verboseLevel vLevel, const char* message);
	bool f_writeToConsole(const verboseLevel vLevel, const char* message);

	int m_verboseLevel = verboseLevel::DEBUG; // Informational
	std::string f_getVerboseLevelString(const verboseLevel vLevel);

	bool m_doLog = true;

public:

	LogHandler();
	LogHandler(bool doLog, bool writeToConsole, bool writeToFile, std::string filename);
	~LogHandler();

	bool setLogPath(const char * inputLogPath);
	bool setServiceName(const char * inputServiceName);
	bool setWriteToFile(const bool inputWriteToFile);
	bool setWriteToConsole(const bool inputWriteToConsole);
	bool setVerboseLevel(const int inputVerboseLevel);

	bool reloadConfiguration();

	void PrintLogPath() { std::cout << "LogPath: " << m_logPath << std::endl; }
	void PrintDate() { f_getSystemDateFormatted(); }

	std::string Debug(const char* message);
	std::string Informational(const char* message);
	std::string Warning(const char* message);
	std::string Error(const char* message);
	std::string Critical(const char* message);

	bool doLog();
};

#endif // !LOG_HANDLER_HPP