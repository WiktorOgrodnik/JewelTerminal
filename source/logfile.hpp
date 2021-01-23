#pragma once

#include "pch.hpp"

class Log
{
private:

    bool active;
    std::string fileName;
    std::string path;
    std::ofstream logFileDev;

    Log();
    Log(const Log&);
    ~Log();

    std::string getSystemDate();
    void lineContents(std::string logContent);

public:

    static Log& New(std::string logContent);

};