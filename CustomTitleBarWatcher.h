#ifndef CUSTOMTITLEBARWATCHERH_H
#define CUSTOMTITLEBARWATCHERH_H

#endif // CUSTOMTITLEBARWATCHERH_H


#include <QWidget>
#include <QMouseEvent>

class cTitlebar : public QWidget
{
    private:
        QWidget *m_parent;
        QPoint m_pCursor;

    public:
        cTitlebar(QWidget *parent);
        ~cTitlebar();

    protected:
        void mousePressEvent(QMouseEvent *event) override;
        void mouseMoveEvent(QMouseEvent *event) override;
};
