#include "testsimple.h"

TestSimple::TestSimple(QObject *parent) : QObject(parent)
{

}

void TestSimple::felixIstDumm()
{
    QVERIFY (true == true);
}
