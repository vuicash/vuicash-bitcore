#ifndef VUIVERSIONCHECKER_H
#define VUIVERSIONCHECKER_H

#include <QObject>

#define VUI_RELEASES "https://github.com/vuicash/qtum/releases"

class Version {

public:
    int _major;
    int _minor;
    int _revision;

    Version(){
        SetNull();
    }

    Version(int maj, int min, int rev){
        SetNull();

        _major = maj;
        _minor = min;
        _revision = rev;
    }

    Version(QString str){
        SetNull();

        QStringList parts = str.split(".");

        if(!parts.isEmpty())
            _major = parts[0].toInt();
        if(parts.length() > 1)
            _minor = parts[1].toInt();
        if(parts.length() > 2)
            _revision = parts[2].toInt();
    }

    Version(const Version &v){
        _major = v._major;
        _minor = v._minor;
        _revision = v._revision;
    }

    bool operator >(const Version& other) const
    {
    bool retValue =
            _major > other._major ?         true :
            _minor > other._minor ?         true :
            _revision > other._revision ?   true :
                                            false;
    return retValue;
    }

    bool operator <(const Version& other) const
    {
    bool retValue =
            _major < other._major ?         true :
            _minor < other._minor ?         true :
            _revision < other._revision ?   true :
                                            false;
    return retValue;
    }

    bool operator ==(const Version& other) const
    {
    bool retValue =
            _major != other._major ?        false :
            _minor != other._minor ?        false :
            _revision != other._revision ?  false :
                                            true;
    return retValue;
    }

    void SetNull()
    {
        _major = 0;
        _minor = 0;
        _revision = 0;
    }
};

class VuicashVersionChecker : public QObject
{
    Q_OBJECT
public:
    explicit VuicashVersionChecker(QObject *parent = 0);
    ~VuicashVersionChecker();

    bool newVersionAvailable();

private:
    QList<Version> getVersions();
    Version getMaxReleaseVersion();

    Version currentVersion;
};

#endif // VUIVERSIONCHECKER_H
