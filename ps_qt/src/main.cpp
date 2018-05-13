#include <QApplication>
#include <psmainwindow.h>
#include <CL/cl.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PSMainWindow win;

    std::vector<cl::Platform> all_platforms;

    cl::Platform::get(&all_platforms);

    for (auto &platform : all_platforms) {
        std::cout << platform.getInfo<CL_PLATFORM_NAME>() << std::endl;
    }

    win.show();


    return a.exec();
}
