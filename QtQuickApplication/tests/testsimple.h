#ifndef TESTSIMPLE_H
#define TESTSIMPLE_H

#include <QObject>
#include <QtTest/QtTest>

class TestSimple : public QObject
{
    Q_OBJECT
public:
    explicit TestSimple(QObject *parent = nullptr);

signals:

public slots:

private slots:
    void felixIstDumm();
};

#endif // TESTSIMPLE_H
