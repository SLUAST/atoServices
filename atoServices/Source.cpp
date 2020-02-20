/*
	atoServices sandbox
*/
#include "atoServices.hpp"

int main()
{

	LogHandler log(true, true, true, "atoServices");

	log.setVerboseLevel(verboseLevel::DEBUG);

	log.Debug("HEJSAN");
}