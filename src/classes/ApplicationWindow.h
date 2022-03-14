#pragma once

#include <QString>

#include <QLabel>
#include <QWidget>
#include <QPixmap>
#include <QByteArray>
#include <QBoxLayout>

class ApplicationWindow: public QWidget
{
    private:
        QLabel *weatherText;
        QLabel *weatherIcon;

        QBoxLayout *rootLayout;
        QBoxLayout *leftLayout;
        QBoxLayout *rightLayout;

    public:
        ApplicationWindow();

        void setWeatherText(const QString string);
        void setWeatherIcon(QByteArray iconData);
};
