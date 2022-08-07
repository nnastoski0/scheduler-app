#include "CustomTitleBarWatcher.h"
#include "qwidget.h"

cTitlebar::cTitlebar(QWidget *parent ) :m_parent(parent)
{

}

cTitlebar::~cTitlebar(){

}

void cTitlebar::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_pCursor = event->globalPosition().toPoint() - m_parent->geometry().topLeft();
        event->accept();
    }
}

void cTitlebar::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {   
        //m_parent->resize(800,800);
        m_parent->showNormal();
        m_parent->move(event->globalPosition().toPoint() - m_pCursor);
        event->accept();

    }
}



