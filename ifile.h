#ifndef IFILE_H
#define IFILE_H

#include <QObject>
#include <QString>
#include <QFileDialog>

class IFile : public QObject
{
     Q_OBJECT
public:
    explicit IFile(QObject *parent = 0);

signals:
    void sendToQml(QString text);

public slots:
    void getFromQml(QString text);

    Q_INVOKABLE void newFile();
    Q_INVOKABLE void openFile();
    Q_INVOKABLE void saveFile();

private:
    QString text;
};

#endif // IFILE_H
