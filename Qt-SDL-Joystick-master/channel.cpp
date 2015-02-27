#include <QDebug>
#include "channel.h"


Channel::Channel(int channelId,
                 QString name,
                 int joyId,
                 int axisId,
                 QWidget *parent) :
                 QWidget(parent)

{
    setObjectName(QString::fromUtf8("ch%1%2")
                  .arg(channelId + 1)
                  .arg(name)
                  );
//    qDebug() << "new" << this;

    QString txt = QString("CH%1").arg(channelId + 1);

}

Channel::~Channel()
{
//    qDebug() << "delete" << this;
    delete ui;
}

void Channel::setVal(int value)
{
}
