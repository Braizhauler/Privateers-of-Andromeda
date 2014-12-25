/**********************************************************
* File: logfile.cc
* Author: Greg Howlett (GregTHowlett@Gmail.com)
* Created: 2014 DEC 19
* Version: 0
* Revised: 2014 DEC 19
*
* © [2014] Dwarfholm.com
* All Rights Reserved.
************************************************************/

#include "logfile.h"


/*******************************
* Constructors and Destructor */
LogFile::LogFile(const char * filename,
                 LogLevel defaultMessageType) {
	ofile_.open( filename );
}

LogFile::~LogFile(void) {
  if (ofile_.is_open()) {
    ofile_.close();
  }
}


/*******************************
* Methods                     */
bool LogFile::Write(const char * message) {
  if (ofile_.is_open()) {
    return Write(default_log_level_, message);
  }
  return false;
}

bool LogFile::Write(LogLevel log_level, const char * message) {
  if (ofile_.is_open()) {
    time_t current_time = std::time(NULL);
    char current_time_char[26];
    ctime_s(current_time_char, 26, &current_time);
    ofile_ << current_time_char << ": " << LogLevelString(log_level) << message << std::endl;
    ofile_.flush();
    return true;
  }
  return false;
}

/*******************************
* Accessors and Mutators      */


/*******************************
* Friend Functions            */
LogFile & operator<<(LogFile & log_file, const char * message)

{
  if (log_file.ofile_.is_open())
    log_file.Write(message);
  return log_file;
}
//Returns a human readable string to print in the log file representing the LogLevel of the message
const char * LogFile::LogLevelString(LogLevel log_level) const {
  switch(log_level) {
    case LogLevel::LOG_ERROR: {
      return "ERROR: ";
      break;
    }
    case LogLevel::LOG_WARNING: {
      return "Warn : ";
      break;
    }
    case LogLevel::LOG_INFO: {
      return "Info : ";
      break;
    }
    case LogLevel::LOG_DEBUG: {
      return "debug: ";
      break;
    }
    default: {
    }
  }
}
