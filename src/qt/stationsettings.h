#ifndef STATIONSETTINGS_H
#define STATIONSETTINGS_H

#include <QObject>
#include <QSettings>
#include <QDebug>

class StationSettings : public QObject
{
    Q_OBJECT

public:
    explicit StationSettings(QObject *parent = 0);

    enum PositionAmbiguity {
        NONE,
        point11,
        onePoint15,
        elevenPoint51,
        sixtyNinePoint09
    };


    Q_PROPERTY(QString callsign READ callsign WRITE setCallsign NOTIFY callsignChanged)
    Q_PROPERTY(bool sendCompressed READ sendCompressed WRITE setSendCompressed NOTIFY sendCompressedChanged)
    Q_PROPERTY(QString lat READ lat WRITE setLat NOTIFY latChanged)
    Q_PROPERTY(QString lon READ lon WRITE setLon NOTIFY lonChanged)
    Q_PROPERTY(QString comment READ comment WRITE setComment NOTIFY commentChanged)
    Q_PROPERTY(bool hasPHGD READ hasPHGD WRITE sethasPHGD NOTIFY hasPHGDChanged)
    Q_PROPERTY(char group READ group WRITE setGroup NOTIFY groupChanged)
    Q_PROPERTY(char symbol READ symbol WRITE setSymbol NOTIFY symbolChanged)
    Q_PROPERTY(StationSettings::PositionAmbiguity positionAmbiguity READ positionAmbiguity WRITE setPositionAmbiguity NOTIFY positionAmbiguityChanged)

    QString m_callsign;
    QString m_comment;

    QString m_lat;
    QString m_lon;

    bool m_hasPHGD;
    bool m_sendCompressed;

    char m_group;
    char m_symbol;

    StationSettings::PositionAmbiguity m_positionAmbiguity;




QString callsign() const
{
    return m_callsign;
}

QString lat() const
{
    return m_lat;
}

QString lon() const
{
    return m_lon;
}

QString comment() const
{
    return m_comment;
}

void saveSettings(QSettings &settings);

bool hasPHGD() const
{
    return m_hasPHGD;
}

bool sendCompressed() const
{
    return m_sendCompressed;
}

void restoreFromSettings(QSettings &settings);
char group() const
{
    return m_group;
}

char symbol() const
{
    return m_symbol;
}


StationSettings::PositionAmbiguity positionAmbiguity() const
{
    return m_positionAmbiguity;
}

signals:
void callsignChanged(QString arg);
void latChanged(QString arg);
void lonChanged(QString arg);
void commentChanged(QString arg);

void hasPHGDChanged(bool arg);

void sendCompressedChanged(bool arg);

void groupChanged(char arg);

void symbolChanged(char arg);

void positionAmbiguityChanged( StationSettings::PositionAmbiguity arg);

public slots:

void setCallsign(QString arg)
{
    if (m_callsign != arg) {
        m_callsign = arg;
        emit callsignChanged(arg);
    }
}
void setLat(QString arg)
{
    if (m_lat != arg) {
        m_lat = arg;
        emit latChanged(arg);
    }
}

void setLon(QString arg)
{
    if (m_lon != arg) {
        m_lon = arg;
        emit lonChanged(arg);
    }
}
void setComment(QString arg)
{
    if (m_comment != arg) {
        m_comment = arg;
        emit commentChanged(arg);
    }
}
void sethasPHGD(bool arg)
{
    if (m_hasPHGD != arg) {
        m_hasPHGD = arg;
        emit hasPHGDChanged(arg);
    }
}
void setSendCompressed(bool arg)
{
    if (m_sendCompressed != arg) {
        m_sendCompressed = arg;
        emit sendCompressedChanged(arg);
    }
}
void setGroup(char arg)
{
    if (m_group != arg) {
        m_group = arg;
        emit groupChanged(arg);
    }
}
void setSymbol(char arg)
{
    if (m_symbol != arg) {
        m_symbol = arg;
        emit symbolChanged(arg);
    }
}
void setPositionAmbiguity(PositionAmbiguity arg)
{
    if (m_positionAmbiguity != arg) {
        m_positionAmbiguity = arg;
        emit positionAmbiguityChanged(arg);
    }
}
};

#endif // STATIONSETTINGS_H
