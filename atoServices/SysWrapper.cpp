#include "SysWrapper.hpp"

SysWrapper::SysWrapper()
{
}

SysWrapper::~SysWrapper()
{
}

std::string SysWrapper::execCmd(const char* cmd)
{
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);

    if (!pipe)
    {
        throw std::runtime_error("popen() failed!");
    }

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
    {
        result += buffer.data();
    }

    //printf("::: %s \n", cmd);

    std::cout << "Executed command: " << cmd << std::endl;
    return result;
}

std::string SysWrapper::makeDir(const char* path)
{
    char cmd[80];

    strcat(cmd, "/bin/mkdir ");
    strcat(cmd, path);

    std::string returnValue = execCmd(cmd);

    return std::string(returnValue);
}

std::string SysWrapper::makeDirRecur(const char* path)
{
    char cmd[80];

    strcat(cmd, "/bin/mkdir -p ");
    strcat(cmd, path);

    std::string returnValue = execCmd(cmd);

    return std::string(returnValue);
}