#ifndef SIMPLE_HTTP_SERVER_HPP
#define SIMPLE_HTTP_SERVER_HPP

#include "LogHandler.hpp"

class HTTPServer {
private:
	bool Initialize();

	LogHandler logger;

public:

	HTTPServer();
	~HTTPServer();


};
#endif // !SIMPLE_HTTP_SERVER_HPP
