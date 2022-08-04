#include "CustomTitleBar.h"
#include "qboxlayout.h"
#include "qwidget.h"
#include "qpushbutton.h"

cTitlebar::cTitlebar(QWidget *parent ) :m_parent(parent)
{

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
        m_parent->move(event->globalPosition().toPoint() - m_pCursor);
        event->accept();
    }
}