#ifndef FIELDMODEL_H
#define FIELDMODEL_H


#include <QObject>

QT_BEGIN_NAMESPACE
class QTimer;
QT_END_NAMESPACE

 using Field = QVector<QVector<int>>;

class FieldModel: public QObject
{
    Q_OBJECT

public:
    enum TypeCell{EMPTY, SNAKE, WALL, FOOD};
    enum DirectionMove{LEFT, RIGHT, UP, DOWN};
    enum GameStatus{INGAME, PAUSE, GAMEOVER, BEGIN};

    FieldModel(int m_sizeField, int m_scoreToSpeedUp, QObject *parent = nullptr);
    ~FieldModel() = default;
    int size() const;
    int getData(int i, int j) const;
    bool setData(int i, int j, int value);
    DirectionMove getDirectionMove() const;
    void setDirectionMove(const DirectionMove &value);
    bool getStepIsDone() const;
    void setDefaultField();
    void createFood();
    GameStatus getGameStatus() const;
    int getSpeed();

public slots:
    void newGame();
    void pauseGame();
    void gameOver();
    void speedUp();
    void move();
signals:
    void dataUpdated();
    void scoreUpdated(int);
    void speedUpdated(int);
    void gameStatusChanged(GameStatus);

private:    
    const int m_sizeField;
    const int m_scoreToSpeedUp;
    Field m_field;
    QVector<QPair<int, int>> m_snake;
    DirectionMove m_directionMove = UP;
    GameStatus m_gameStatus = BEGIN;
    bool m_stepIsDone = true;
    int m_score = 0;
    int m_speed = 1;

    QTimer *m_timerMove;
    QTimer *m_timerSpeedUp;
};

#endif // FIELDMODEL_H
