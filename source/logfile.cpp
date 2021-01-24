#include "logfile.hpp"

Log::Log()
{
    /**
     * Singleton pattern constructor
     * 
     * @brief -Make new log file, with custom name
     * -Open file and print test log
     */

    this->active = false;
    this->path = "log/";
    this->fileName = this->getSystemDate();

    this->logFileDev.open(this->path + this->fileName + ".log");

    if (this->logFileDev.good())
    {
        this->logFileDev << this->fileName << ": Successful creation of the log file\n";
        this->active = true;
        this->logFileDev.close();   
    }
    else std::cerr << "Can not create file " << this->fileName << ".log" << '\n';
}

std::string Log::getSystemDate()
{
    /**
     * @brief -count system date and time
     * 
     * @return system date and time in std::string
     */

    time_t now = time(0);
    tm ltm;
    char buffer[80];

#ifdef LINUX

    localtime_r(&now, &ltm);

#endif

#ifdef WINDOWS

    localtime_s(&ltm, &now);

#endif

    strftime(buffer, 80, "%d-%m-%Y %H-%M-%S", &ltm);
	return "jewel.exe " + std::string(buffer);
}

void Log::lineContents(std::string logContent)
{
    /**
     * @brief -print line to log file
     * 
     * @return void
     */
	if (this->active)
	{
		std::string date = getSystemDate();

		this->logFileDev.open(this->path + this->fileName + ".log", std::ios::app);

		this->logFileDev << date << ": " << logContent << '\n';

		this->logFileDev.close();
	}
}

Log& Log::New(std::string logContent)
{
    /**
     * @brief -Singleton pattern getInstance
     * -print new log
     * 
     * @return Log instance
     */

	static Log instance;
	instance.lineContents(logContent);
	return instance;
}

Log::~Log()
{
    /**
     * Destructor
     * 
     */
}