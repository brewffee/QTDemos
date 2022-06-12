#include <iostream>

#include <QApplication>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QMenuBar>
#include <QStatusBar>
#include <QTextEdit>
#include <QTimer>
#include <QFont>

#include "lol.h"

int main (int argc, char *argv[]) {
    // goal: basic notepad with a menubar and statusbar
    QApplication app(argc, argv);

    QMainWindow *pad = new QMainWindow();
    pad -> resize(640, 480);
    pad -> setWindowTitle("Basic Notepad");

    QMenuBar *menubar = new QMenuBar;

    // add some dummy menus
    QMenu *fileMenu = menubar -> addMenu("File");
    QMenu *editMenu = menubar -> addMenu("Edit");
    QMenu *helpMenu = menubar -> addMenu("Help");
    pad -> setMenuBar(menubar);


    QStatusBar *statusbar = new QStatusBar;

    QLabel *statusbarText = new QLabel;
    statusbarText -> setText("Ready");
    statusbar -> addWidget(statusbarText);

    pad -> setStatusBar(statusbar);

    // create text area
    QTextEdit *textArea = new QTextEdit;
    textArea -> setLineWrapMode(QTextEdit::NoWrap);

    // QWidget *widget = new QWidget;
    // widget -> setLayout(layout);

    pad -> setCentralWidget(textArea);
    pad -> show();

    return app.exec();
}