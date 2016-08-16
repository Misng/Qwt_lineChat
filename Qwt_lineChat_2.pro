SOURCES += \
    main.cpp \
    mainwidget.cpp

LIBS += -L/usr/lib/lib -lqwt

HEADERS += \
    timescaledraw.h \
    mainwidget.h


include(./COM/COM.pri)
