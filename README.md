# WeatherWidget

This is the simple Qt5/C++ desktop widget for getting current weather from openweather api and showing it.
### Installation

```bash
$ qmake
$ make

$ mkdir ~/.local/share/qwidget
$ cp ./dist/* ~/.local/share/qwidget
$ sudo ln -s ~/.local/share/qwidget/widget /usr/bin/

$ widget
```

### Usage
Open **config.json** in widget dir and replace latitude and longitude.
Register at the [openweather](https://openweathermap.org/), go to '**My Api Keys**',
create new or use one of existing keys, replace key in config by this, wait 5-10 minutes and
start your widget.

### Dependencies
* QtCore
* QtWidgets
* QtNetwork
