#include "screenmovewatcher.h"
#include "qcoreevent.h"
#include <QPushButton>

ScreenMoveWatcher::ScreenMoveWatcher(QObject *parent)
    : QObject{parent}
{

}

ScreenMoveWatcher::~ScreenMoveWatcher(){
}

bool ScreenMoveWatcher::eventFilter(QObject *watched, QEvent *event){

    QPushButton *button = qobject_cast<QPushButton*>(watched);

    if(!button){
        return false;
    }

    if(event->type() == QEvent::Move){
        //the screen has been moved, therefore we reset the icon to the default
        button->setIcon(QIcon(":/Resources/Icons/expand-arrows.svg"));
        return true;
    }

    return false;
}
