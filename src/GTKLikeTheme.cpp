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
    mainWindow.resize(640, 360);
    mainWindow.setStyleSheet("background-color: #fafafa;");

    QLabel label("Hello World!");
    label.setFont(QFont("Product Sans", 32, QFont::Bold));
    label.setAlignment(Qt::AlignCenter);
    label.setContentsMargins(16, 16, 16, 16);

    QPushButton button1("Click Me!");
    QPushButton button2("Click Me Too!");
    QPushButton button3("No, Click Me!");

    QHBoxLayout buttonGroup;
    buttonGroup.setContentsMargins(16, 0, 16, 16);
    buttonGroup.addWidget(&button1);
    buttonGroup.addWidget(&button2);
    buttonGroup.addWidget(&button3);

    button1.setFont(QFont("Product Sans", 12, QFont::Bold));
    button2.setFont(QFont("Product Sans", 12, QFont::Bold));
    button3.setFont(QFont("Product Sans", 12, QFont::Bold));

    // default button styles
    stylesheet buttonStyle = {
        {"background:", "#e6e6e6;"},
        // {"border:", "2px solid #fefefe;"},
        {"padding:", "8px 12px;"},
        {"border-radius:", "6px;"},
    };

    stylesheet buttonHover = {
        {"background:", "#dcdcdc;"},
        // {"border:", "2px solid #ededed;"},
    };

    stylesheet buttonActive = {
        {"background:", "#bebebe;"},
        // {"border:", "2px solid #dcdcdc;"},
    };

    // primary button styles
    stylesheet primaryButtonStyle = {
        {"background:", "#3584e4;"},
        {"color:", "#ffffff;"},
        {"padding:", "8px 12px;"},
        {"border-radius:", "6px;"},
    };

    stylesheet primaryButtonHover = {
        {"background:", "#4990e7;"},
        // {"border:", "2px solid #ededed;"},
    };

    stylesheet primaryButtonActive = {
        {"background:", "#2a6ab6;"},
        // {"border:", "2px solid #dcdcdc;"},
    };

    addStyle(&button1, buttonStyle, buttonHover, buttonActive);
    addStyle(&button2, buttonStyle, buttonHover, buttonActive);
    addStyle(&button3, primaryButtonStyle, primaryButtonHover, primaryButtonActive);

    // create a drop shadow effect for each button
    // QGraphicsDropShadowEffect effect = QGraphicsDropShadowEffect();
    // effect.setBlurRadius(16);
    // effect.setColor(QColor(0, 0, 0, 32));
    // effect.setOffset(0, 4);

    // QGraphicsDropShadowEffect effect2 = QGraphicsDropShadowEffect();
    // effect2.setBlurRadius(16);
    // effect2.setColor(QColor(0, 0, 0, 32));
    // effect2.setOffset(0, 4);

    // QGraphicsDropShadowEffect effect3 = QGraphicsDropShadowEffect();
    // effect3.setBlurRadius(16);
    // effect3.setColor(QColor(0, 0, 0, 32));
    // effect3.setOffset(0, 4);

    // button1.setGraphicsEffect(&effect);
    // button2.setGraphicsEffect(&effect2);
    // button3.setGraphicsEffect(&effect3);

    QLabel link("<a href=\"https://www.google.com/search?q=hello+world\"><span style=\"color:#777;\">Alternatively, click me</span></a>");
    link.setFont(QFont("Product Sans", 12));
    link.setAlignment(Qt::AlignCenter);
    link.setContentsMargins(16, 0, 16, 8);

    QWidget test;
    test.setStyleSheet("background-color: #fff; border-radius: 6px;");
    test.setContentsMargins(16, 0, 16, 16);

    QGraphicsDropShadowEffect effect = QGraphicsDropShadowEffect();
    effect.setBlurRadius(16);
    effect.setColor(QColor(0, 0, 0, 32));
    effect.setOffset(0, 0);

    test.setGraphicsEffect(&effect);

    QVBoxLayout testLayout;
    testLayout.setContentsMargins(0, 0, 0, 0);

    testLayout.addWidget(&label);
    testLayout.addLayout(&buttonGroup);
    testLayout.addWidget(&link);
    testLayout.setAlignment(Qt::AlignCenter);

    test.setLayout(&testLayout);

    QVBoxLayout mainLayout;
    //mainLayout.addWidget(&label);
    //mainLayout.addLayout(&buttonGroup);
    //mainLayout.addWidget(&link);
    //mainLayout.addWidget(&test);
    //mainLayout.setAlignment(Qt::AlignCenter);
    mainLayout.addWidget(&test);
    mainLayout.setAlignment(Qt::AlignCenter);

    mainLayout.setSpacing(12);
    
    mainWindow.setLayout(&mainLayout);   
    mainWindow.show();

    return app.exec();
}
