#include <ApplicationWindow.h>

ApplicationWindow::ApplicationWindow()
{
    this->layout = new QBoxLayout(QBoxLayout::TopToBottom, this);

    this->weatherText = new QLabel();

    this->layout->addWidget(this->weatherText);
}

void ApplicationWindow::setWeatherText(const QString string)
{
    this->weatherText->setText(string);
}
