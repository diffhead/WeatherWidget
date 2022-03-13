#pragma once

#include <QString>

#include <QLabel>
#include <QWidget>
#include <QBoxLayout>

class ApplicationWindow: public QWidget
{
    private:
        QLabel *weatherText;

        QBoxLayout *layout;

    public:
        ApplicationWindow();

        void setWeatherText(const QString string);
};
