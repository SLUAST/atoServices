#ifndef SYS_WRAPPER_HPP
#define SYS_WRAPPER_HPP

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <stdio.h>
#include <string.h>

class SysWrapper {
private:

public:
	SysWrapper();
	~SysWrapper();

	std::string execCmd(const char* cmd);

	std::string makeDir(const char* path);
	std::string makeDirRecur(const char* path);

	std::string listDir(const char* path);
	std::string listDirTime(const char* path);

	std::string deleteDir(const char* path);
	std::string deleteDirRecur(const char* path);



	std::string touchFile(const char* filename);
	std::string touchFileAbs(const char* filepath);

	std::string readFile(const char* filename);
	std::string readFileAbs(const char* filename);

	std::string createFile(const char* filename);
	std::string createFileAbs(const char* filename);

	std::string copyFile(const char* frompath, const char* topath);
	std::string copyFilePerm(const char* frompath, const char* topath);

	std::string moveFile(const char* frompath, const char* topath);
	std::string renameFile(const char* frompath, const char* topath);

	std::string chmodFile(const char* filepath, const char* permissions);

	std::string setACL(const char* filepath, const char* acl);

	std::string userGetId(const char* username);
	std::string userGetEnt(const char* username);

	std::string getSysTime(const char* input);
	std::string getSysDate(const char* input);


	std::string getHostname(const char* input);

	std::string getIfconfig(const char* input);

	std::string getACL(const char* path);


	std::string compressFileGzip(const char* filename);
	std::string compressFileZip(const char* filename);


};


#endif // !SYS_WRAPPER_HPP