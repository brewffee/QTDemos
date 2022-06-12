#ifndef helper_h
#define helper_h
#endif

#include <string>
#include <typeinfo>
#include <QWidget>

typedef std::map <std::string, std::string> stylesheet;

// stylesheet style = {
//    {"background:", "#ff0000;"},
//    {"color:", "#ffffff;"},
// };
//
// stylesheet hoverStyle = { ... };
// 
// addStyle(button, style, hoverStyle);

int addStyle(QWidget *widget, stylesheet style, stylesheet hoverStyle = {}, stylesheet activeStyle = {}) {
    // create a string to hold the style
    std::string styleString = "QWidget {";
    std::string hoverString = "";
    std::string activeString = "";

    // iterate through the stylesheet
    for (auto x = style.begin(); x != style.end(); ++x) {
        styleString += x -> first; // "key:"
        styleString += x -> second; // "value;"
    }

    styleString += "}";

    if (hoverStyle.size() > 0) {
        hoverString += " QWidget:hover {";

        // iterate through the stylesheet
        for (auto x = hoverStyle.begin(); x != hoverStyle.end(); ++x) {
            hoverString += x -> first; // "key:"
            hoverString += x -> second; // "value;"
        }

        hoverString += "}";
    }

    if (activeStyle.size() > 0) {
        activeString += " QWidget:pressed {";

        // iterate through the stylesheet
        for (auto x = activeStyle.begin(); x != activeStyle.end(); ++x) {
            activeString += x -> first; // "key:"
            activeString += x -> second; // "value;"
        }

        activeString += "}";
    }

    QString qStyleString = QString::fromStdString(styleString) + QString::fromStdString(hoverString) + QString::fromStdString(activeString);
    printf("%s\n", qStyleString.toStdString().c_str());
    widget -> setStyleSheet(
        QString::fromStdString(styleString) + ' ' +
        QString::fromStdString(hoverString) + ' ' +
        QString::fromStdString(activeString)
    );

    return 0;
}

