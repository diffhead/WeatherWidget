#include <ApplicationWindow.h>

ApplicationWindow::ApplicationWindow(): QWidget(nullptr, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint)
{
    this->rootLayout = new QBoxLayout(QBoxLayout::LeftToRight, this);

    this->leftLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    this->rightLayout = new QBoxLayout(QBoxLayout::TopToBottom);

    this->rootLayout->addLayout(this->leftLayout);
    this->rootLayout->addLayout(this->rightLayout);

    this->weatherText = new QLabel();

    this->weatherIcon = new QLabel();
    this->weatherIcon->resize(50, 50);

    this->leftLayout->addWidget(this->weatherIcon);
    this->rightLayout->addWidget(this->weatherText);
}

void ApplicationWindow::setWeatherText(const QString string)
{
    this->weatherText->setText(string);
}

void ApplicationWindow::setWeatherIcon(QByteArray icon)
{
    QPixmap pixmap(50, 50);

    pixmap.loadFromData(icon);

    this->weatherIcon->setPixmap(pixmap);
}
