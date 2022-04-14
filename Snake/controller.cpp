#include "controller.h"

#include <QDebug>

Controller::Controller(QObject *parent): QObject(parent)
{

}

FieldModel *Controller::getFieldModel() const
{
    return fieldModel;
}

void Controller::setFieldModel(FieldModel *_fieldModel)
{
    fieldModel = _fieldModel;
}

void Controller::keyPressEvent(QKeyEvent *event)
{
     //while getStepIsDone() is false, it block the reaction on the moving keys, until the step is not done
    switch (event->key()) {
        case Qt::Key_Left:
            if(fieldModel->getStepIsDone() && fieldModel->getDirectionMove() != FieldModel::RIGHT)
                fieldModel->setDirectionMove(FieldModel::LEFT);
            break;
        case Qt::Key_Right:
            if(fieldModel->getStepIsDone() && fieldModel->getDirectionMove() != FieldModel::LEFT)
                fieldModel->setDirectionMove(FieldModel::RIGHT);
            break;
        case Qt::Key_Up:
            if(fieldModel->getStepIsDone() && fieldModel->getDirectionMove() != FieldModel::DOWN)
                fieldModel->setDirectionMove(FieldModel::UP);
            break;
        case Qt::Key_Down:
            if(fieldModel->getStepIsDone() && fieldModel->getDirectionMove() != FieldModel::UP)
                fieldModel->setDirectionMove(FieldModel::DOWN);
            break;
        default:
            break;
    }
}
