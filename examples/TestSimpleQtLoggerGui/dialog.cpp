/*
  Test Simple Logger for Qt

  Mario Ban, 06.2015

*/

#include "dialog.h"
#include "ui_dialog.h"
#include "simpleQtLogger.h"
#include "eventLog.h"

Dialog::Dialog(QWidget *parent)
  : QDialog(parent)
  , ui(new Ui::Dialog)
{
  L_FUNC("");
  qDebug("Dialog::Dialog"); // TODO comment this
  ui->setupUi(this);

  EventLog *eventLog = new EventLog(this);
  QObject::connect(eventLog, SIGNAL(eventInfo(const QString&)), this, SLOT(eventInfo(const QString&)));
  installEventFilter(eventLog);
}

Dialog::~Dialog()
{
  L_FUNC("");
  qDebug("Dialog::~Dialog"); // TODO comment this
  delete ui;
}

void Dialog::on_pushButtonQuit_clicked()
{
  L_FUNC("");
  L_INFO("Bye bye");
  close();
}

void Dialog::eventInfo(const QString& text)
{
  // L_FUNC("");
  ui->textBrowserLog->append(text);
  L_INFO(text);
}
