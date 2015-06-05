/*
  Simple Logger for Qt

  Mario Ban, 05.2015

*/

#include "SimpleQtLogger.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QtDebug>

/* Log-level */
bool SQT_LOG_ENABLE_FATAL = true;
bool SQT_LOG_ENABLE_ERROR = true;
bool SQT_LOG_ENABLE_WARNING = true;
bool SQT_LOG_ENABLE_INFO = true;
bool SQT_LOG_ENABLE_DEBUG = false;
bool SQT_LOG_ENABLE_FUNCTION = false;

// -------------------------------------------------------------------------------------------------

// define one GLOBAL instance in main: SimpleQtLogger simpleQtLogger_;

// -------------------------------------------------------------------------------------------------

SimpleQtLogger::SimpleQtLogger()
  : _logFileSize(0)
  , _logFileNumber(0)
  , _stackDepth(0)
{
  qDebug("SimpleQtLogger::SimpleQtLogger");
}

SimpleQtLogger::~SimpleQtLogger()
{
  qDebug("SimpleQtLogger::~SimpleQtLogger");

  // TODO: close log file
}

void SimpleQtLogger::setLogFileName(const QString& logFileName, unsigned int logFileSize, unsigned int logFileNumber)
{
  qDebug("SimpleQtLogger::setLogFileName");
  _logFileName = logFileName;
  _logFileSize = logFileSize;
  _logFileNumber = logFileNumber;

  // TODO: open log file
}

void SimpleQtLogger::log(const QString& text, SQT_LOG_Level level, const QString& functionName, const char* fileName, unsigned int lineNumber)
{
  // qDebug("SimpleQtLogger::log");

  // TODO: append to log file, handle file rolling

  qDebug("%s", QString("%6: [%1] %2 (%3@%4:%5)").arg(LOG_LEVEL_CHAR[level]).arg(text).arg(functionName).arg(fileName).arg(lineNumber).arg(_logFileName).toStdString().c_str());
}

void SimpleQtLogger::logFuncBegin(const QString& text, const QString& functionName, const QString& fileName, unsigned int lineNumber)
{
  // qDebug("SimpleQtLogger::logFuncBegin");

  // TODO stack-trace depth (++ before) ... (thread-id-callback?)

  _stackDepth++;

  QString stackDepth("");
  for(unsigned int i=1; i<_stackDepth; ++i) {
    stackDepth += " ";
  }
  log(QString("%1\\ %2").arg(stackDepth).arg(text), SQT_LOG_FUNCTION, functionName, fileName.toStdString().c_str(), lineNumber);
}

void SimpleQtLogger::logFuncEnd(const QString& text, const QString& functionName, const QString& fileName, unsigned int lineNumber)
{
  // qDebug("SimpleQtLogger::logFuncEnd");

  // TODO stack-trace depth (-- after) ... (thread-id-callback?)

  QString stackDepth("");
  for(unsigned int i=1; i<_stackDepth; ++i) {
    stackDepth += " ";
  }
  log(QString("%1/ %2").arg(stackDepth).arg(text), SQT_LOG_FUNCTION, functionName, fileName.toStdString().c_str(), lineNumber);

  _stackDepth--;
}

// -------------------------------------------------------------------------------------------------

SimpleQtLoggerFunc::SimpleQtLoggerFunc(const QString& text, const QString& functionName, const QString& fileName, unsigned int lineNumber)
  : _text(text)
  , _functionName(functionName)
  , _fileName(fileName)
  , _lineNumber(lineNumber)
{
  // qDebug("SimpleQtLoggerFunc::SimpleQtLoggerFunc");
  if(ENABLED_SQT_LOG_FUNCTION && SQT_LOG_ENABLE_FUNCTION) simpleQtLogger_.logFuncBegin(text, _functionName, _fileName, _lineNumber);
}

SimpleQtLoggerFunc::~SimpleQtLoggerFunc()
{
  // qDebug("SimpleQtLoggerFunc::~SimpleQtLoggerFunc");
  if(ENABLED_SQT_LOG_FUNCTION && SQT_LOG_ENABLE_FUNCTION) simpleQtLogger_.logFuncEnd(_text, _functionName, _fileName, _lineNumber);
}
