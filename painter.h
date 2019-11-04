#ifndef PAINTER_H
#define PAINTER_H

#include <QObject>
#include <QtQuick/QQuickPaintedItem>
#include <QPainter>


#include <QFile>
#include <QFileDialog>
#include <QPoint>

#include <QColor>
#include <QBrush>
#include <QPen>

#include <QDebug>

#include <ebuttontype.h>

class Painter : public QQuickPaintedItem
{
    Q_OBJECT
    //Q_PROPERTY(ButtonType Btype READ Btype WRITE setBtype NOTIFY BtypeChanged)

    int x_start, y_start, x_end, y_end, x_now, y_now;
    QPoint pos_start;
    QPoint pos_end;
    QPoint pos_now;

public:
    explicit Painter(QQuickItem *parent = nullptr);

    void paint(QPainter *painter) override;

    Q_INVOKABLE void mousePressEvent(int x, int y);
    Q_INVOKABLE void mouseReleaseEvent(int x, int y);
    Q_INVOKABLE void mouseMoveEvent(int x, int y);
    EButtonType::ButtonType Btype;
public slots:
    Q_INVOKABLE void setBtype(EButtonType::ButtonType type);
/*
    Q_INVOKABLE void newFile();
    Q_INVOKABLE void openFile();
    Q_INVOKABLE void saveFile();

    void getFileName(QString fileName); // from qml

signals:
    void transFileName(QString fileName); // to qml
    */
};

#endif // PAINTER_H
