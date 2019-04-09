QT += core gui opengl widgets

CONFIG -= \
    app_bundle \
    console \

CONFIG += \
    c++11 \
    debug \

TARGET = graphical_app 

LIBS += \
    -L../vector2d -lvector2d \
    -L../game_structure -lgame_structure \

PRE_TARGETDEPS += \
    ../vector2d/libvector2d.a \
    ../game_structure/libgame_structure.a \

INCLUDEPATH += \
    ../vector2d \
    ../game_structure \

SOURCES += \
    main_qt_gl.cc \
    glwidget.cc \
    vue_opengl.cc

HEADERS += \
    glwidget.h \
    vertex_shader.h \
    vue_opengl.h \
    ../general/dessinable.h \
    ../general/support_a_dessin.h \

RESOURCES += \
    resource.qrc
