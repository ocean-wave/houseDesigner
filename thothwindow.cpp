#include "thothwindow.h"
#include "ui_thothwindow.h"

ThothWindow::ThothWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ThothWindow)
{
    ui->setupUi(this);
    // ALERT! Use the following code to get keyboard focus at your OpenGL widget
    ui->contextGL->setFocusPolicy(Qt::StrongFocus);
    ui->contextGL->setFocus();
}

ThothWindow::~ThothWindow()
{
    delete ui;
}

