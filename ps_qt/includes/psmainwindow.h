#ifndef PSMAINWINDOW_H
#define PSMAINWINDOW_H

#include <QMainWindow>

namespace PSApp {
    enum  {
        WIDTH = 600,
        HEIGHT = 550
    };
}

class PSMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit PSMainWindow(QWidget *parent = nullptr);

signals:

public slots:

private:
};

#endif // PSMAINWINDOW_H
