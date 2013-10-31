/*
  This file was generated by the Html5 Application wizard of Qt Creator.
  Html5ApplicationViewer is a convenience class containing mobile device specific
  code such as screen orientation handling.
  It is recommended not to modify this file, since newer versions of Qt Creator
  may offer an updated version of it.
*/

#ifndef WEBTOUCHNAVIGATION_H
#define WEBTOUCHNAVIGATION_H

#include "webtouchevent.h"
#include "webtouchphysics.h"
#include "webtouchphysicsinterface.h"
#include "webtouchscroller.h"
#include <QTimer>

class QWebPage;

class WebTouchNavigation : public QObject
{
    Q_OBJECT

public:
    WebTouchNavigation(QObject *object, QWebPage *webPage);
    virtual ~WebTouchNavigation();

protected:
    bool eventFilter(QObject *object, QEvent *event);
    void handleDownEvent(const WebTouchEvent &event);
    void handleMoveEvent(const WebTouchEvent &event);
    void handleReleaseEvent(const WebTouchEvent &event);

public slots:
    void hoverTimerFired();
    void downTimerFired();
    void quickDownTimerFired();
    void quickUpTimerFired();

private:
    void invalidateLastTouchDown();
    void generateMouseEvent(const WebTouchEvent &touchEvent);

private:
    WebTouchPhysicsInterface* m_physics;
    WebTouchScroller* m_scroller;
    WebTouchEvent m_touchDown;
    QObject* m_viewObject;
    QWebPage* m_webPage;
    QWebFrame* m_webFrame;
    QTimer m_downTimer;
    QTimer m_hoverTimer;
    QTimer m_quickDownTimer;
    QTimer m_quickUpTimer;
    bool m_suppressMouseEvents;
};

#endif // WEBTOUCHNAVIGATION_H
