#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include "fieldmodel.h"
#include "controller.h"
#include "celldecorator.h"

#include <QFrame>

class FieldView: public QFrame
{
    Q_OBJECT

public:

    FieldView(QWidget *parent = nullptr);

    void setFieldModel(FieldModel *_fieldModel);
    FieldModel *getFieldModel() const;

    Controller *getController() const;
    void setController(Controller *value);
    bool getDrawEmptyCells() const;
    void setDrawEmptyCells(bool value);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

public slots:
    void gameStatusChanged(FieldModel::GameStatus);

private:
    Controller *m_controller = new Controller;
    CellDecorator *m_cellDecorator = new CellDecorator;
    FieldModel *m_fieldModel = nullptr;

    bool m_drawEmptyCells = false;
    bool m_recieveMouseButtons = false;

    qreal m_widthCell = 0;
    qreal m_heightCell = 0;
    int m_countCells = 0;
};

#endif // FIELDVIEW_H
