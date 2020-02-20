#include "HTTPServer.hpp"

bool HTTPServer::Initialize()
{
	/*
		Will create log files under /opt/vigil/logs/ with the prefix 'SimpleHTTPServer'
	*/
	if (logger.setLogPath("/opt/vigil/logs/") && \
		logger.setServiceName("SimpleHTTPServer") && \
		logger.setWriteToFile(true) && \
		logger.setWriteToConsole(false) && \
		logger.setVerboseLevel(verboseLevel::DEBUG))
	{
		logger.Debug("Initialize method in SimpleHTTPServer done!");
	}

	return false;
}

HTTPServer::HTTPServer()
{
	if (logger.doLog())
	{
		logger.Debug("SimpleHTTPServer Constructor");
	}
}

HTTPServer::~HTTPServer()
{
	if (logger.doLog())
	{
		logger.Debug("SimpleHTTPServer Destructor");
	}
}
