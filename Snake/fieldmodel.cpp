#include "fieldmodel.h"

#include <QRandomGenerator>
#include <QTimer>

FieldModel::FieldModel(int sizeField,int scoreToSpeedUp, QObject *parent):
    QObject(parent),
    m_sizeField(sizeField),
    m_scoreToSpeedUp(scoreToSpeedUp),
    m_field(m_sizeField, QVector<int>(m_sizeField,0)),
    m_timerMove(new QTimer(this)),
    m_timerSpeedUp(new QTimer(this))
{

    connect(m_timerMove, &QTimer::timeout, this, &FieldModel::move);
    m_timerSpeedUp->setSingleShot(true);
    connect(m_timerSpeedUp, &QTimer::timeout, this, &FieldModel::speedUp);
}

int FieldModel::size() const
{
    return m_sizeField;
}

int FieldModel::getData(int i, int j) const
{
    return m_field[i][j];
}

bool FieldModel::setData(int i, int j, int value)
{
    if(i < m_sizeField && j < m_sizeField){
        m_field[i][j] = value;
        emit dataUpdated();
        return true;
    }
    return false;
}

void FieldModel::move()
{
    static const int turns[4][2] = {{0, -1}, {0, 1},
                                    {-1, 0}, {1, 0}};

    int rowHead = m_snake[0].first + turns[m_directionMove][0];

    if(rowHead == m_sizeField)
        rowHead = 0;
    if(rowHead == -1)
        rowHead = m_sizeField - 1;
    int colHead = m_snake[0].second + turns[m_directionMove][1];
    if(colHead == m_sizeField)
        colHead = 0;
    if(colHead == -1)
        colHead = m_sizeField - 1;

    switch (m_field[rowHead][colHead]) {
    case TypeCell::WALL:
    case TypeCell::SNAKE:
        gameOver();
        break;
    case TypeCell::FOOD:{
        m_snake.push_back({rowHead, colHead});
        ++m_score;
        if(m_score%m_scoreToSpeedUp == 0){
            m_timerMove->stop();
            m_timerSpeedUp->start(1000);
        }
        createFood();
        [[fallthrough]];
    }
    default:{

        int n = m_snake.size();
        m_field[m_snake[n-1].first][m_snake[n-1].second] = TypeCell::EMPTY;
        for(int i = n - 1; i > 0; --i){
            m_snake[i] = m_snake[i-1];
        }
        m_snake[0].first = rowHead;
        m_snake[0].second = colHead;
        m_field[rowHead][colHead] = TypeCell::SNAKE;
    }
    }

    m_stepIsDone = true;
    emit scoreUpdated(m_score);
    emit dataUpdated();

}

FieldModel::GameStatus FieldModel::getGameStatus() const
{
    return m_gameStatus;
}

int FieldModel::getSpeed()
{
    return 300/m_speed;
}

bool FieldModel::getStepIsDone() const
{
    return m_stepIsDone;
}

void FieldModel::setDefaultField()
{
    //add perimeter wall
    for(int i = 0; i < m_sizeField; ++i){
        for(int j = 0; j < m_sizeField; ++j){
            if(i == 0 || i == m_sizeField - 1 || j == 0 || j == m_sizeField - 1)
                m_field[i][j] = TypeCell::WALL;
            else
                m_field[i][j] = TypeCell::EMPTY;
        }
    }

    m_snake.clear();

    // add snake
    m_field[m_sizeField/2 - 1][m_sizeField/2] = TypeCell::SNAKE;
    m_field[m_sizeField/2][m_sizeField/2] = TypeCell::SNAKE;
    m_field[m_sizeField/2 + 1][m_sizeField/2] = TypeCell::SNAKE;

    m_snake.push_back({m_sizeField/2 - 1 , m_sizeField/2});
    m_snake.push_back({m_sizeField/2 , m_sizeField/2});
    m_snake.push_back({m_sizeField/2 + 1 , m_sizeField/2});
}

void FieldModel::createFood()
{

    int rowFood, colFood;
    do{
        rowFood = QRandomGenerator::global()->bounded(m_sizeField);
        colFood = QRandomGenerator::global()->bounded(m_sizeField);
    }
    while(m_field[rowFood][colFood] != 0);

    m_field[rowFood][colFood] = TypeCell::FOOD;
    dataUpdated();

}

void FieldModel::newGame()
{
    setDefaultField();
    createFood();
    m_directionMove = UP;
    m_gameStatus = INGAME;
    m_score = 0;
    m_speed = 1;
    emit gameStatusChanged(m_gameStatus);
    emit scoreUpdated(m_score);
    emit speedUpdated(m_speed);
    m_timerMove->start(getSpeed());
}

void FieldModel::pauseGame()
{

    if(m_gameStatus == INGAME){
        m_gameStatus = PAUSE;
        m_timerMove->stop();
    }
    else if(m_gameStatus == PAUSE){
        m_gameStatus = INGAME;
        m_timerMove->start(getSpeed());
    }

    emit gameStatusChanged(m_gameStatus);
}

void FieldModel::gameOver()
{
    m_timerMove->stop();
    m_gameStatus = GAMEOVER;
    emit gameStatusChanged(m_gameStatus);
}

void FieldModel::speedUp()
{
    ++m_speed;
    emit speedUpdated(m_speed);
    m_timerMove->start(getSpeed());
}

FieldModel::DirectionMove FieldModel::getDirectionMove() const
{
    return m_directionMove;
}

void FieldModel::setDirectionMove(const DirectionMove &value)
{
    m_directionMove = value;
    m_stepIsDone = false;
}
