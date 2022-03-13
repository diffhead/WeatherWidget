#include <ApplicationWindow.h>

ApplicationWindow::ApplicationWindow()
{
    this->layout = new QBoxLayout(QBoxLayout::TopToBottom, this);

    this->rootLabel = new QLabel();

    this->layout->addWidget(this->rootLabel);
}

void ApplicationWindow::setWeatherText(const QString string)
{
    this->rootLabel->setText(string);
}
