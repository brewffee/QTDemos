// Launcher for the various QT demos

#include <iostream>

#include <QApplication>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QProcess>
#include <QDir>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow *window = new QMainWindow;
    window -> resize(480, 640);
    window -> setWindowTitle("Select a demo to launch");

    QDir dir("demos");
    QStringList files = dir.entryList();

    QVBoxLayout *layout = new QVBoxLayout;
    // align top 
    layout -> setAlignment(Qt::AlignTop);

    for (int i = 0; i < files.size(); i++) {
        if (files[i] == "." || files[i] == "..") {
            continue;
        }

        QPushButton *button = new QPushButton(files[i]);
        layout -> addWidget(button);

        QObject::connect(button, &QPushButton::clicked, [=]() {
            QString path = "demos/" + files[i];
            QProcess::startDetached(path);
        });
    };

    QWidget *widget = new QWidget;
    widget -> setLayout(layout);

    window -> setCentralWidget(widget);

    window -> show();

    return app.exec();
}
