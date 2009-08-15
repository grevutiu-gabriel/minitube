#ifndef VIDEOAREAWIDGET_H
#define VIDEOAREAWIDGET_H

#include <QWidget>
#include <QTimer>
#include "video.h"
#include "loadingwidget.h"
#include "ListModel.h"

class VideoAreaWidget : public QWidget {

    Q_OBJECT

public:
    VideoAreaWidget(QWidget *parent);
    void setVideoWidget(QWidget *videoWidget);
    void setLoadingWidget(LoadingWidget *loadingWidget);
    void showLoading(Video* video);
    void showVideo();
    void showError(QString message);
    void setListModel(ListModel *listModel) {
        this->listModel = listModel;
    }

signals:
    void doubleClicked();
    void rightClicked();

protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void mouseMoveEvent (QMouseEvent *event);

private slots:
    void hideMouse();

private:
    QStackedLayout *stackedLayout;
    QWidget *videoWidget;
    LoadingWidget *loadingWidget;
    ListModel *listModel;
    QLabel *messageLabel;
    QTimer *mouseTimer;
};

#endif // VIDEOAREAWIDGET_H
