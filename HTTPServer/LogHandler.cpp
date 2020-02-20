#include "LogHandler.hpp"

void LogHandler::Initialize()
{

}

std::tm* LogHandler::f_getSystemTime()
{
	std::time_t currentTime = std::time(0);
	std::tm* systemTime = std::localtime(&currentTime);

	return systemTime;  // Pointer
}


std::string LogHandler::f_getSystemDateFormatted()
{
	time_t timeRaw;
	struct tm* timeInfo;
	char bufferString[80];

	time(&timeRaw);
	timeInfo = localtime(&timeRaw);

	strftime(bufferString, sizeof(bufferString), "%d-%m-%Y %H:%M:%S", timeInfo);
	std::string dateFormatted(bufferString);

	return dateFormatted;
}

std::string LogHandler::f_getSystemTimeFormatted()
{
	time_t timeRaw;
	struct tm* timeInfo;
	char bufferString[80];

	time(&timeRaw);
	timeInfo = localtime(&timeRaw);

	strftime(bufferString, sizeof(bufferString), "%d-%m-%Y_%H-%M-%S", timeInfo);
	std::string timeFormatted(bufferString);

	return timeFormatted;
}

bool LogHandler::f_writeToFile(const verboseLevel vLevel, const char* message)
{
	std::string verboseString = f_getVerboseLevelString(vLevel);

	std::ofstream logFile;
	std::string fileName = m_currentLogPath;

	logFile.open(fileName, std::ios::app);

	logFile << f_getSystemTimeFormatted() << " - "<< verboseString << " " << message << std::endl;

	logFile.close();
}

bool LogHandler::f_writeToConsole(const verboseLevel vLevel, const char* message)
{
	std::string verboseString = f_getVerboseLevelString(vLevel);

	std::cout << f_getSystemTimeFormatted() << " - " << verboseString << " " << message << std::endl;

}

// TODO: Move this functionality "up the hierarchy", for example to Debug()-method right away
std::string LogHandler::f_getVerboseLevelString(const verboseLevel vLevel)
{
	std::string verboseString = "UNDEFINED";

	switch (vLevel)
	{
	case 0: verboseString = "[DEBUG]";
		break;
	case 1: verboseString = "[INFO]";
		break;
	case 2: verboseString = "[WARN]";
		break;
	case 3: verboseString = "[ERROR]";
		break;
	case 4: verboseString = "[CRITICAL]";
		break;
	default:
		break;
	}

	return verboseString;
}

LogHandler::LogHandler()
{

}

LogHandler::LogHandler(bool inputDoLog, bool inputWriteToConsole, bool inputWriteToFile, std::string inputServiceName)
{
	Initialize();

	this->m_doLog = inputDoLog;
	this->m_writeToConsole = inputWriteToConsole;
	this->m_writeToFile = inputWriteToFile;
	this->m_serviceName = inputServiceName;

	m_currentLogPath = m_logPath;
	m_currentLogPath.append(m_serviceName);
	m_currentLogPath.append("-");
	m_currentLogPath.append(f_getSystemTimeFormatted());
	m_currentLogPath.append(".log");

}

LogHandler::~LogHandler()
{

}

bool LogHandler::setLogPath(const char* inputLogPath)
{
	this->m_logPath = inputLogPath;
	return false;
}

bool LogHandler::setServiceName(const char* inputServiceName)
{
	this->m_serviceName = inputServiceName;

	return false;
}

bool LogHandler::setWriteToFile(const bool inputWriteToFile)
{
	this->m_writeToFile = inputWriteToFile;

	return false;
}

bool LogHandler::setWriteToConsole(const bool inputWriteToConsole)
{
	this->m_writeToConsole = inputWriteToConsole;

	return false;
}

bool LogHandler::setVerboseLevel(const int inputVerboseLevel)
{
	this->m_verboseLevel = inputVerboseLevel;
	return false;
}

std::string LogHandler::Debug(const char* message)
{
	verboseLevel logLevel = verboseLevel::DEBUG;

	if (m_writeToConsole && (m_verboseLevel <= logLevel))
	{
		f_writeToConsole(logLevel, message);
	}

	if (m_writeToFile && (m_verboseLevel <= logLevel))
	{
		f_writeToFile(logLevel, message);
	}

	return std::string();
}

std::string LogHandler::Informational(const char* message)
{
	verboseLevel logLevel = verboseLevel::INFO;

	if (m_writeToConsole && (m_verboseLevel <= logLevel))
	{
		f_writeToConsole(logLevel, message);
	}

	if (m_writeToFile && (m_verboseLevel <= logLevel))
	{
		f_writeToFile(logLevel, message);
	}

	return "end_of_function";
}

std::string LogHandler::Warning(const char* message)
{
	verboseLevel logLevel = verboseLevel::WARN;

	if (m_writeToConsole && (m_verboseLevel <= logLevel))
	{
		f_writeToConsole(logLevel, message);
	}

	if (m_writeToFile && (m_verboseLevel <= logLevel))
	{
		f_writeToFile(logLevel, message);
	}

	return "end_of_function";
}

std::string LogHandler::Error(const char* message)
{
	verboseLevel logLevel = verboseLevel::ERROR;

	if (m_writeToConsole && (m_verboseLevel <= logLevel))
	{
		f_writeToConsole(logLevel, message);
	}

	if (m_writeToFile && (m_verboseLevel <= logLevel))
	{
		f_writeToFile(logLevel, message);
	}

	return "end_of_function";
}

std::string LogHandler::Critical(const char* message)
{
	verboseLevel logLevel = verboseLevel::CRITICAL;
	
	if (m_writeToConsole && (m_verboseLevel <= logLevel))
	{
		f_writeToConsole(logLevel, message);
	}

	if (m_writeToFile && (m_verboseLevel <= logLevel))
	{
		f_writeToFile(logLevel, message);
	}

	return "end_of_function";
}

bool LogHandler::doLog()
{
	return this->m_doLog;
}
