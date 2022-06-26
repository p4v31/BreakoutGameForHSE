#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QtTest/QtTest>

class Test : public QObject
{
    Q_OBJECT

private:
    bool gameMenu()
    {
        return true;
    }
    bool gameWon()
    {
        return false;
    }
    bool gameOver()
    {
        return false;
    }
    bool gameStarted()
    {
        return false;
    }
    bool paused()
    {
        return false;
    }
private slots:
    void initTestCase()
    {
        qDebug("Test is on");
    }
    void firstTest()
    {
        QVERIFY(true);
        QCOMPARE(1,1);
    }
    void cleanupTestCase()
    {
        qDebug("end");
    }
};
#endif // TEST_H
