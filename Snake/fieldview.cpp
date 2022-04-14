#include "fieldview.h"

#include <QPainter>
#include <QDebug>

FieldView::FieldView(QWidget *parent):
    QFrame(parent),
    m_controller(new Controller(this)),
    m_cellDecorator(new CellDecorator(this))
{
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    setFocusPolicy(Qt::StrongFocus);
}

void FieldView::setFieldModel(FieldModel *_fieldModel)
{
    m_fieldModel = _fieldModel;
    m_controller->setFieldModel(m_fieldModel);
    m_countCells = m_fieldModel->size();
    connect(m_fieldModel, &FieldModel::dataUpdated, this, qOverload<>(&FieldView::update));
    connect(m_fieldModel, &FieldModel::gameStatusChanged, this, &FieldView::gameStatusChanged);
    update();
}

void FieldView::paintEvent(QPaintEvent * event)
{
    QFrame::paintEvent(event);
    QPainter painter(this);
    QFont font = painter.font();
    font.setPixelSize(20);
    painter.setFont(font);
    if(m_fieldModel != nullptr){
        switch (m_fieldModel->getGameStatus()) {
        case FieldModel::INGAME:{
            
            for(int i = 0; i < m_countCells; ++i){
                for(int j = 0; j < m_countCells; ++j){
                    
                    int typeCell = m_fieldModel->getData(i,j);
                    
                    if(!(typeCell == FieldModel::EMPTY && !m_drawEmptyCells))
                        
                        m_cellDecorator->drawCell(painter, QRectF(j * m_widthCell ,  i * m_heightCell ,
                                                               m_widthCell , m_heightCell ), typeCell);
                }
            }
            break;
        }
        case FieldModel::PAUSE:{
            painter.drawText(rect(), Qt::AlignCenter, tr("PAUSE"));
            break;
        }
        case FieldModel::GAMEOVER:
            painter.drawText(rect(), Qt::AlignCenter, tr("GAME OVER"));
            break;
        case FieldModel::BEGIN:
            painter.drawText(rect(), Qt::AlignCenter, tr("Welcome to game Snake"));
            break;
        }
    }
}

void FieldView::keyPressEvent(QKeyEvent *event)
{
    m_controller->keyPressEvent(event);
}

void FieldView::resizeEvent(QResizeEvent *)
{
    m_widthCell = static_cast<qreal>(width()) / m_countCells;
    m_heightCell = static_cast<qreal>(height()) / m_countCells;
}

void FieldView::gameStatusChanged(FieldModel::GameStatus)
{
    update();
}

bool FieldView::getDrawEmptyCells() const
{
    return m_drawEmptyCells;
}

void FieldView::setDrawEmptyCells(bool value)
{
    m_drawEmptyCells = value;
}

FieldModel *FieldView::getFieldModel() const
{
    return m_fieldModel;
}

Controller *FieldView::getController() const
{
    return m_controller;
}

void FieldView::setController(Controller *value)
{
    m_controller = value;
}
