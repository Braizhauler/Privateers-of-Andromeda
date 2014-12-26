/*******************************************************************************
* File: logfile.h
* Author: Greg Howlett (GregTHowlett@Gmail.com)
* Created: 2014 DEC 19
* Version: 0
* Revised: 2014 DEC 19
*
*
* LogFile:
* Manages a file stream for outputting a game log file.
*
* © [2014] Dwarfholm.com
* All Rights Reserved.
*******************************************************************************/

#ifndef LOGFILE_H_
#define LOGFILE_H_

#include <ctime>
#include <fstream>

enum LogLevel	{ //Add strings for additional enums in LogLevel to LogLevelString().
	LOG_ERROR = 0,
	LOG_WARNING,
	LOG_INFO,
	LOG_DEBUG,	};

class LogFile
{
public:

	explicit LogFile(const char * filename = "errorlog.log",
                   LogLevel default_log_level = LOG_ERROR);
	~LogFile(void);
  void ErrorCallbackForGLWF(int error, const char* description);
	bool Write(const char * message);
	bool Write(LogLevel, const char * message);
	friend LogFile & operator<< (LogFile &, const char * message);
private:
  const char * LogLevelString(LogLevel) const;
	std::ofstream ofile_;
  LogLevel default_log_level_;
};

#endif  // LOG_FILE_H_