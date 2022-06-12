#include <iostream>

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <QLineEdit>

#include "lol.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget mainWindow;
    mainWindow.resize /* 16:9 */ (1280, 720);
    mainWindow.setWindowTitle("QT Layout Test: Content with Sidebar");

    mainWindow.setStyleSheet("background: #fafafa;");

    // Sidebar widget
    QWidget sidebar;
    sidebar.setStyleSheet("background: #fff");
    sidebar.resize(200, 720);
    sidebar.move(1280 - 200, 0);

    // Content widget
    QWidget content;
    content.setStyleSheet("background: #aaa");
    content.resize(1280 - 200, 720);
    content.move(0, 0);

    // add the sidebar to the main window
    mainWindow.setLayout(new QHBoxLayout);

    mainWindow.layout() -> addWidget(&sidebar);

    // add the content to the main window
    mainWindow.layout() -> addWidget(&content);

    // finish
    mainWindow.show();

    return app.exec();
}

