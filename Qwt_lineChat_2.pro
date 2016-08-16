SOURCES += \
    main.cpp \
    mainwidget.cpp

LIBS += -L/usr/lib/lib -lqwt

HEADERS += \
    timescaledraw.h \
    mainwidget.h


INCLUDEPATH += $$PWD/../API/QtDemo/Linux32
DEPENDPATH += $$PWD/../API/QtDemo/Linux32
