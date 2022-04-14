#include "celldecorator.h"

CellDecorator::CellDecorator(QObject *parent): QObject(parent)
{

}

void CellDecorator::drawCell(QPainter &painter, QRectF rect, int typeCell)
{

    QColor color(Qt::white);
    switch (typeCell) {
    case 1:
        color = QColor(Qt::darkGreen);
        break;
    case 2:
        color = QColor(128, 64 ,0);
        break;
    case 3:
        color = QColor(Qt::darkYellow);
        break;
      }

    painter.setBrush(QBrush(color));
    painter.drawRect(rect);
}
