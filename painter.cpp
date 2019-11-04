#include "painter.h"

Painter::Painter(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    x_start = y_start = x_end = y_end = 0;

}

void Painter::paint(QPainter *painter)
{
    painter->setRenderHints(QPainter::Antialiasing, true);

    //painter->drawEllipse();
    switch (Btype)
    {
    case EButtonType::ButtonType::PENCIL:
        painter->drawPoint(x_start, y_start);
        break;
    case EButtonType::ButtonType::LINE:
        painter->drawLine(x_start, y_start, x_end, y_end);
        break;
    case EButtonType::ButtonType::RECTANCGLE:
        painter->drawRect(x_start, y_start, x_end, y_end);
        break;
    case EButtonType::ButtonType::ELLIPSE:
        painter->drawEllipse(x_start, y_start, x_end, y_end);
        break;
    case EButtonType::ButtonType::ERASE:

        break;
    default:
        break;
    }
    update();
}

void Painter::mousePressEvent(int x, int y)
{
    x_start = x;
    y_start = y;
}

void Painter::mouseReleaseEvent(int x, int y)
{
    x_end = x;
    y_end = y;
}

void Painter::mouseMoveEvent(int x, int y)
{
    x_end = x;
    y_end = y;
}

void Painter::setBtype(EButtonType::ButtonType type)
{
    Btype = type;
    qDebug() << Btype;
}

/*
void Painter::newFile()
{

}

void Painter::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,"Open XML","C:\\","*.jpg;;*.png");
    transFileName(fileName);
}

void Painter::saveFile()
{

}

void Painter::getFileName(QString filename)
{
    emit transFileName(filename);
}
*/
