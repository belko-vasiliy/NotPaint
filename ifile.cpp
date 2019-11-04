#include "ifile.h"

IFile::IFile(QObject *parent) : QObject(parent)
{

}

void IFile::getFromQml(QString text)
{
    text = QFileDialog::getOpenFileName(nullptr,"Open XML","C:\\","*.jpg;;*.png");
    text = "D:\\T_o.jpg";
    emit sendToQml(text);
}

void IFile::newFile()
{

}

void IFile::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,"Open XML","C:\\","*.jpg;;*.png");

}

void IFile::saveFile()
{

}
