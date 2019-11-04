#ifndef EBUTTONTYPE_H
#define EBUTTONTYPE_H

#include <QObject>

class EButtonType
{
    Q_GADGET
public:
    //EButtonType();
    enum class  ButtonType {PENCIL, LINE, ELLIPSE, RECTANCGLE, ERASE};
    Q_ENUM(ButtonType)
};

#endif // EBUTTONTYPE_H
