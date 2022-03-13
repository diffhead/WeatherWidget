#pragma once

#include <QString>

#include <QLabel>
#include <QWidget>
#include <QBoxLayout>

class ApplicationWindow: public QWidget
{
    private:
        QLabel *rootLabel;

        QBoxLayout *layout;

    public:
        ApplicationWindow();

        void setWeatherText(const QString string);
};
