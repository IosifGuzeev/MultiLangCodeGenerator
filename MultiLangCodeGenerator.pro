QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Factories/CSharpFactory/csharpclassunit.cpp \
        Factories/CSharpFactory/csharpfactory.cpp \
        Factories/CSharpFactory/csharpmethodunit.cpp \
        Factories/CSharpFactory/csharpprintcommand.cpp \
        Factories/CppFactory/cppclassunit.cpp \
        Factories/CppFactory/cppfactory.cpp \
        Factories/CppFactory/cppmethodunit.cpp \
        Factories/CppFactory/cppprintcommand.cpp \
        Factories/JavaFactory/javaclassunit.cpp \
        Factories/JavaFactory/javafactory.cpp \
        Factories/JavaFactory/javamethodunit.cpp \
        Factories/JavaFactory/javaprintcommand.cpp \
        Tests/cpptest.cpp \
        Tests/csharptest.cpp \
        Tests/javatest.cpp \
        Utilities/tools.cpp \
        Utilities/writers.cpp \
        codefactory.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Factories/CSharpFactory/csharpclassunit.h \
    Factories/CSharpFactory/csharpfactory.h \
    Factories/CSharpFactory/csharpmethodunit.h \
    Factories/CSharpFactory/csharpprintcommand.h \
    Factories/CppFactory/cppclassunit.h \
    Factories/CppFactory/cppfactory.h \
    Factories/CppFactory/cppmethodunit.h \
    Factories/CppFactory/cppprintcommand.h \
    Factories/JavaFactory/javaclassunit.h \
    Factories/JavaFactory/javafactory.h \
    Factories/JavaFactory/javamethodunit.h \
    Factories/JavaFactory/javaprintcommand.h \
    Tests/cpptest.h \
    Tests/csharptest.h \
    Tests/javatest.h \
    Utilities/tools.h \
    Utilities/writers.h \
    codefactory.h \
    interfaces.h

DISTFILES += \
    Tests/CSharpCases/case1.txt \
    Tests/CppCases/case1.txt \
    Tests/JavaCases/case1.txt
