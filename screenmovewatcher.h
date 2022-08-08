#ifndef SCREENMOVEWATCHER_H
#define SCREENMOVEWATCHER_H

#include <QObject>

class ScreenMoveWatcher : public QObject
{
    Q_OBJECT
public:
    explicit ScreenMoveWatcher(QObject *parent = nullptr);
    ~ScreenMoveWatcher();
    virtual bool eventFilter(QObject *watched, QEvent *event);

signals:

};

#endif // SCREENMOVEWATCHER_H
