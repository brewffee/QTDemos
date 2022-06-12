#include <iostream>

#include <QApplication>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QTableWidget>
#include <QPushButton>
#include <QDialog>
#include <QLineEdit>

#include <QHeaderView>

int main (int argc, char *argv[]) {
    // goal: basic table showing key/value pairs, along with an edit dialog
    QApplication app(argc, argv);

    QMainWindow *window = new QMainWindow;
    /* 16:3 aspect ratio */ window -> resize(640, 480);
    window -> setWindowTitle("Create and View Data");

    // create the table and add it to the window
    QTableWidget *table = new QTableWidget;
    table -> setColumnCount(2);
    // name the columns
    table -> setHorizontalHeaderItem(0, new QTableWidgetItem("Key"));
    table -> setHorizontalHeaderItem(1, new QTableWidgetItem("Value"));

    // populate the table
    for (int i = 0; i < 10; i++) {
        table -> insertRow(i);
        table -> setItem(i, 0, new QTableWidgetItem("key_" + QString::number(i)));
        table -> setItem(i, 1, new QTableWidgetItem(QString::number(i)));
    }

    // stretch the columns to fit the contents
    table -> horizontalHeader() -> setSectionResizeMode(0, QHeaderView::Stretch);
    table -> horizontalHeader() -> setSectionResizeMode(1, QHeaderView::Stretch);

    // remove initial selection
    table -> setCurrentCell(-1, -1);

    // allow only one row to be selected at a time
    table -> setSelectionBehavior(QAbstractItemView::SelectRows);
    table -> setSelectionMode(QAbstractItemView::SingleSelection);

    // disable editing (use the edit dialog instead)
    table -> setEditTriggers(QAbstractItemView::NoEditTriggers);
   
    // add some action buttons
    QPushButton *delButton = new QPushButton("Delete");
    QPushButton *editButton = new QPushButton("Edit");
    QPushButton *addButton = new QPushButton("Add");

    // button container
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout -> addWidget(delButton);
    buttonLayout -> addWidget(editButton);
    buttonLayout -> addWidget(addButton);

    // set button widths + alignment
    delButton -> setFixedWidth(100);
    editButton -> setFixedWidth(100);
    addButton -> setFixedWidth(100);

    buttonLayout -> setAlignment(Qt::AlignRight);

    // add functionality to the buttons
    delButton -> setEnabled(false);
    editButton -> setEnabled(false);

    // when an item is selected
    table -> connect(table, &QTableWidget::itemSelectionChanged, [=]() {
        delButton -> setEnabled(true);
        editButton -> setEnabled(true);
    });

    // when the delete button is clicked
    delButton -> connect(delButton, &QPushButton::clicked, [=]() {
        // check if a key or a value is selected
        bool isKey = table -> currentItem() -> column() == 0;
        
        if (isKey) {
            table -> removeRow(table -> currentRow());
        } else {
            table -> currentItem() -> setText("null");
            // if this value was actually required in code,
            // we'd just convert the string to NULL :P
        }

        // clearSelection() counts as a selection change,
        // must be called before disabling the buttons
        table -> clearSelection();

        delButton -> setEnabled(false);
        editButton -> setEnabled(false);
    });

    // when the edit button is clicked
    editButton -> connect(editButton, &QPushButton::clicked, [=]() {
        // create a dialog to edit the key and value
        QDialog *dialog = new QDialog;
        dialog -> setWindowTitle("Edit Item");

        QLabel *keyLabel = new QLabel("Key");
        QLabel *valueLabel = new QLabel("Value");

        QLineEdit *keyEdit = new QLineEdit;
        QLineEdit *valueEdit = new QLineEdit;

        keyEdit -> setText(table -> item(table -> currentRow(), 0) -> text());

        QString value = table -> item(table -> currentRow(), 1) -> text();

        if (value != "null") {
            valueEdit -> setText(value);
        }

        // add some buttons
        QPushButton *okButton = new QPushButton("OK");
        QPushButton *cancelButton = new QPushButton("Cancel");

        QGridLayout *layout = new QGridLayout;
        layout -> addWidget(keyLabel, 0, 0);
        layout -> addWidget(keyEdit, 0, 1);
        layout -> addWidget(valueLabel, 1, 0);
        layout -> addWidget(valueEdit, 1, 1);

        QHBoxLayout *buttonLayout = new QHBoxLayout;
        buttonLayout -> addWidget(okButton);
        buttonLayout -> addWidget(cancelButton);

        layout -> addLayout(buttonLayout, 2, 1);

        dialog -> setLayout(layout);

        // when the OK button is clicked
        okButton -> connect(okButton, &QPushButton::clicked, [=]() {
            // get the key and value from the text boxes
            QString key = keyEdit -> text();
            QString value = valueEdit -> text();
            if (value.isEmpty()) {
                value = "null";
            }

            table -> item(table -> currentRow(), 0) -> setText(key);
            table -> item(table -> currentRow(), 1) -> setText(value);
            dialog -> close();
        });

        // when the cancel button is clicked
        cancelButton -> connect(cancelButton, &QPushButton::clicked, [=]() {
            dialog -> close();
        });

        // modalize the dialog
        dialog -> exec();
    });

    // when the add button is pressed 
    addButton -> connect(addButton, &QPushButton::clicked, [=]() {
        // remember selected row (if not selected, append to end of table)
        int row = table -> currentRow();

        if (row == -1) {
            row = table -> rowCount();
        } else {
            row++;
        }

        QDialog *dialog = new QDialog;
        dialog -> setWindowTitle("Add Item");

        QLabel *keyLabel = new QLabel("Key");
        QLabel *valueLabel = new QLabel("Value");

        QLineEdit *keyEdit = new QLineEdit;
        QLineEdit *valueEdit = new QLineEdit;

        QGridLayout *layout = new QGridLayout;
        layout -> addWidget(keyLabel, 0, 0);
        layout -> addWidget(keyEdit, 0, 1);
        layout -> addWidget(valueLabel, 1, 0);
        layout -> addWidget(valueEdit, 1, 1);

        // add some buttons
        QPushButton *okButton = new QPushButton("OK");
        QPushButton *cancelButton = new QPushButton("Cancel");

        // add the buttons to the dialog
        QHBoxLayout *buttonLayout = new QHBoxLayout;
        buttonLayout -> addWidget(okButton);
        buttonLayout -> addWidget(cancelButton);

        layout -> addLayout(buttonLayout, 2, 1);

        dialog -> setLayout(layout);

        // when the OK button is clicked
        okButton -> connect(okButton, &QPushButton::clicked, [=]() {
            // get the key and value from the text boxes
            QString key = keyEdit -> text();
            QString value = valueEdit -> text();
            if (value.isEmpty()) {
                value = "null";
            }

            table -> insertRow(row);

            table -> setItem(row, 0, new QTableWidgetItem(key));
            table -> setItem(row, 1, new QTableWidgetItem(value));

            dialog -> close();
        });

        // when the cancel button is clicked
        cancelButton -> connect(cancelButton, &QPushButton::clicked, [=]() {
            dialog -> close();
        });

        // modalize the dialog
        dialog -> exec();
    });   

    // create a vertical layout to hold the table and buttons
    QVBoxLayout *layout = new QVBoxLayout;
    layout -> addWidget(table);
    layout -> addLayout(buttonLayout);

    // create a widget to hold the layout (ugh)
    QWidget *widget = new QWidget;
    widget -> setLayout(layout);

    // add the widget to the window
    window -> setCentralWidget(widget);

    window -> show();

    return app.exec();
}