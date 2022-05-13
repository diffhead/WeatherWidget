#include <iostream>

#include <QApplication>

#include <classes/ApplicationConfig.h>
#include <classes/ApplicationHandler.h>

#define WIDGET_VERSION "0.1"

using std::cout;

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    ApplicationConfig config;

    if ( config.isInitialized() == false ) {
        cout << "Failed configuration initialization\n";

        return 1;
    }

    ApplicationHandler handler(&application, QString(WIDGET_VERSION), &config);

    handler.setApplicationWindowTitle("Weather Widget");
    handler.showApplicationWindow(200, 100);

    handler.startWeatherMonitoring();

    return application.exec();
}
