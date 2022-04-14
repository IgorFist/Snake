#ifndef CELLDELEGATE_H
#define CELLDELEGATE_H

#include <QPainter>
#include <QPixmap>

class CellDecorator: public QObject
{
public:
    CellDecorator(QObject *parent = nullptr);
    void drawCell(QPainter& painter, QRectF rect, int typeCell);
};

#endif // CELLDELEGATE_H
