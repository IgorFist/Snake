#include "mainwindow.h"

#include <QPushButton>
#include <QLCDNumber>
#include <QLabel>
#include <QSettings>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_setting(new QSettings("config.ini", QSettings::IniFormat, this)),
      m_lcdBestScore(new QLCDNumber),
      m_bestScore(m_setting->value("bestScore",0).toInt())
{
    resize(500, 500);
    setCentralWidget(new QWidget());
    QGridLayout *gridLayout = new QGridLayout();
    centralWidget()->setLayout(gridLayout);

    QPushButton* startPb = new QPushButton("start");
    gridLayout->addWidget(startPb, 0, 0);
    startPb->setFocusPolicy(Qt::NoFocus);

    QPushButton* pausePb = new QPushButton("pause");
    gridLayout->addWidget(pausePb, 1, 0);
    pausePb->setFocusPolicy(Qt::NoFocus);

    QFont fontLabel("Helvetica [Cronyx]", 12);

    QLabel *speedLabel = new QLabel("Speed ", this);
    speedLabel->setFont(fontLabel);
    speedLabel->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    gridLayout->addWidget(speedLabel, 0, 1);
    QLCDNumber* lcdSpeed = new QLCDNumber(this);
    lcdSpeed->setSegmentStyle(QLCDNumber::Flat);
    gridLayout->addWidget(lcdSpeed, 1, 1);


    QLabel *scoreLabel = new QLabel("Score ", this);
    scoreLabel->setFont(fontLabel);
    scoreLabel->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    gridLayout->addWidget(scoreLabel, 0, 2);
    QLCDNumber* lcdScore = new QLCDNumber(this);
    lcdScore->setSegmentStyle(QLCDNumber::Flat);
    gridLayout->addWidget(lcdScore, 1, 2);

    QLabel *bestScoreLabel = new QLabel("Best score ", this);
    bestScoreLabel->setFont(fontLabel);
    bestScoreLabel->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    gridLayout->addWidget(bestScoreLabel, 0, 3);
    m_lcdBestScore = new QLCDNumber(this);
    m_lcdBestScore->setSegmentStyle(QLCDNumber::Flat);
    m_lcdBestScore->display(m_bestScore);
    gridLayout->addWidget(m_lcdBestScore, 1, 3);


    FieldView *fieldView = new FieldView(this);
    fieldView->setDrawEmptyCells(true);
    gridLayout->addWidget(fieldView, 2, 0, 4, 4);

    FieldModel *fieldModel = new FieldModel(m_setting->value("fieldSize",20).toInt(),
                                            m_setting->value("scoreToSpeedUp",10).toInt(), this);
    fieldView->setFieldModel(fieldModel);
    fieldView->setDrawEmptyCells(false);

    connect(startPb, &QPushButton::clicked, fieldModel, &FieldModel::newGame);
    connect(pausePb, &QPushButton::clicked, fieldModel, &FieldModel::pauseGame);
    connect(fieldModel, &FieldModel::scoreUpdated, this, &MainWindow::updateBestScore);
#if __cplusplus >= 201402L
    connect(fieldModel, &FieldModel::scoreUpdated, lcdScore, qOverload<int>(&QLCDNumber::display));
    connect(fieldModel, &FieldModel::speedUpdated, lcdSpeed, qOverload<int>(&QLCDNumber::display));
#else
    connect(fieldModel, &FieldModel::scoreUpdated, lcdScores, QOverload<int>::of(&QLCDNumber::display));
    connect(fieldModel, &FieldModel::speedUpdated, lcdSpeed, QOverload<int>::of(&QLCDNumber::display));
#endif

}

MainWindow::~MainWindow()
{
    m_setting->setValue("fieldSize", m_setting->value("fieldSize", 20));
    m_setting->setValue("bestScore", m_bestScore);

}

void MainWindow::updateBestScore(int score)
{
    if(score > m_bestScore){
        m_bestScore = score;
        m_lcdBestScore->display(m_bestScore);
    }

}





