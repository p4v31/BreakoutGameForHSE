#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "cloudout.h"
#include "sun.h"
#include "ufoclouds.h"
#include "cloud.h"


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

    }

    void secondTest(){

        QVERIFY(false);

    }

    void thirdTest(){

        QCOMPARE(1,1);

    }

    void fourthTest(){

        QCOMPARE(1,1);

    }

    void fifthTest(){

        QCOMPARE(1,10);

    }

    void sixthTest(){

        QCOMPARE(0,0);

    }

    void seventhTest(){
        QCOMPARE(TimeOfGame, 5);
    }

    void eightTest(){
        QCOMPARE(INITIAL_Y, 150);
    }

    void ninethTest(){
        QCOMPARE(RIGHT_EDGE, 300);
    }

    void tenthtest(){

    }

    void cleanupTestCase()
    {
        qDebug("end");
    }

};
#endif // TEST_H
