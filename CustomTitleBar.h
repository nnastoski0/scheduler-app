#ifndef CUSTOMTITLEBAR_H
#define CUSTOMTITLEBAR_H

#endif // CUSTOMTITLEBAR_H


#include <QWidget>
#include <QMouseEvent>

class cTitlebar : public QWidget
{
    private:
        QWidget *m_parent;
        QPoint m_pCursor;

    public:
        cTitlebar(QWidget *parent);

    protected:
        void mousePressEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
};
