/*
This file contains functions responsible for creating logfiles. The log class is created in singleton design pattern.
It is only one instance of this class and it is achievable form anywhere.
*/

#pragma once

#include "pch.hpp"

class Log
{
private:

    bool active;
    std::string fileName; //Log file name
    std::string path; // path to lof files folder
    std::ofstream logFileDev; // file variable

    //Singleton pattern constructors
    Log();
    Log(const Log&);

    ~Log();

    std::string getSystemDate();
    void lineContents(std::string logContent);

public:

    //Use this function to print new log
    static Log& New(std::string logContent);

};