#include "serial.h"

SerialManager::SerialManager(QObject *parent) : QObject(parent),
    mdata("NULL"),
    portName("ttyUSB1"), // Replace with the name of your Serial Port
    baudRate(115200) // Replace with the Baud Rate of your serial communication

{

    QString usbport;
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    foreach (const QSerialPortInfo &portInfo, ports) {
        qDebug() << "Port Name:" << portInfo.portName();
        qDebug() << "Description:" << portInfo.description();
        qDebug() << "Manufacturer:" << portInfo.manufacturer();

        if(portInfo.manufacturer() == "manufacturer_name"){ //Replace the manufacturer name with your's portInfo.manufacturer() string
            usbport=portInfo.portName();
        }
    }
    portName=usbport;
    serialPort = new QSerialPort(this);
    reconnectTimer = new QTimer(this);

    connect(serialPort, &QSerialPort::errorOccurred, this, &SerialManager::handleSerialError);
    connect(serialPort, &QSerialPort::readyRead, this, &SerialManager::readData);
    connect(reconnectTimer, &QTimer::timeout, this, &SerialManager::startReading);

}

QString SerialManager::data()
{

    return mdata;

}

void SerialManager::setData(QString temp)
{

    if(temp!=""){
        mdata=temp;
    }
    emit dataChanged();

}

SerialManager::~SerialManager()
{
    if (serialPort->isOpen())
        serialPort->close();

}

Q_INVOKABLE void SerialManager::startReading()
{

    if (serialPort->isOpen())
        serialPort->close();

    serialPort->setPortName(portName);
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadWrite))
    {
        qDebug() << "Serial port opened:" << portName;
    }
    else
    {
        QString usbport;
        QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
        foreach (const QSerialPortInfo &portInfo, ports) {
            qDebug() << "Port Name:" << portInfo.portName();
            qDebug() << "Description:" << portInfo.description();
            qDebug() << "Manufacturer:" << portInfo.manufacturer();
            if(portInfo.manufacturer() == "manufacturer_name"){ //Replace the manufacturer name with your's portInfo.manufacturer() string
                usbport=portInfo.portName();
            }
        }
        portName=usbport;
        qDebug() << "Failed to open serial port:" << portName;
        reconnectTimer->start(5000); // Retry after 5 seconds
    }

}

void SerialManager::handleSerialError(QSerialPort::SerialPortError error)
{

    if (error == QSerialPort::ResourceError)
    {
        qDebug() << "Serial port disconnected.";
        reconnectTimer->start(5000); // Retry after 5 seconds        
    }

}


Q_INVOKABLE void SerialManager::writeport(QString a){

    QByteArray buf = a.toLocal8Bit();
    qint64 bytesWritten = serialPort->write(buf);
    if (bytesWritten == -1) {
        qWarning("Failed to write to serial port: %s", qPrintable(serialPort->errorString()));
        return ;
    } else {
        qDebug("Successfully wrote %lld bytes to the serial port", bytesWritten);
    }

}

QByteArray ba,line;
void SerialManager::readData()
{

    QByteArray newData = serialPort->readAll();
    QString str="";
    // Process the received data here
    ba += newData;
    // Process the received data
    int newlineIndex;
    while ((newlineIndex = ba.indexOf('\n')) != -1) {

        line = ba.left(newlineIndex);
        // Handle the line of data here
        qDebug() << "Received line of data:" << line;
        str=QString(line);
        qDebug()<<"str is"<<str;
        setData(str);
        ba.remove(0, newlineIndex + 1);

    }

}





