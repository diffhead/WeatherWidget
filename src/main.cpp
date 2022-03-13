#include <iostream>

#include <QApplication>

#include <classes/ApplicationConfig.h>
#include <classes/ApplicationHandler.h>

using std::cout;

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    ApplicationConfig config;

    if ( config.isInitialized() == false ) {
        cout << "Failed configuration initialization\n";

        return 1;
    }

    ApplicationHandler handler(&application, &config);

    handler.setApplicationWindowTitle("Weather Widget");
    handler.showApplicationWindow(200, 100);

    handler.startWeatherMonitoring();

    return application.exec();
}
