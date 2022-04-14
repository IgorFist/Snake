#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "fieldmodel.h"

#include <QKeyEvent>
#include <QMouseEvent>

class Controller: public QObject
{
public:
    Controller(QObject *parent = nullptr);
    FieldModel *getFieldModel() const;
    void setFieldModel(FieldModel *_fieldModel);
    void keyPressEvent(QKeyEvent *event);
private:
    FieldModel *fieldModel = nullptr;
};

#endif // CONTROLLER_H
