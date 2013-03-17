QT += core \
    gui \
    opengl
unix:!macx:LIBS += -lglut \
    -lGLEW \
    -lGLU \
    -lassimp
macx:LIBS += -framework \
    GLUT
TARGET = Thoth
TEMPLATE = app
SOURCES += Camera.cpp \
    CameraManager.cpp \
    GLWidget.cpp \
    Illumination.cpp \
    main.cpp \
    Model.cpp \
    ModelManager.cpp \
    Point3D.cpp \
    Render.cpp \
    Render2D.cpp \
    Scenary.cpp \
    thothwindow.cpp
HEADERS += Camera.h \
    CameraManager.h \
    GLWidget.h \
    Illumination.h \
    Model.h \
    ModelManager.h \
    Point3D.h \
    Render.h \
    Render2D.h \
    Scenary.h \
    thotwindow.h \
    Util.h 
FORMS += thothwindow.ui
OTHER_FILES += simple.vert \
    simple.frag
