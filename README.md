# qt-rectangles

This is a simple test program to demonstrate performance differences on the
Raspberry Pi.

To run:

    qmake qt-rectangles.pro
    make
    ./qt-rectangles

# Measurements

| Platform   | Commandline                             | Redraw time |
|------------|-----------------------------------------|-------------|
| Pi 3       | ./qt-rectangles -platform xcb           | 29 ms       |
| Pi 3       | ./qt-rectangles -platform eglfs         | 133 ms      |
| Pi 3       | ./qt-rectangles -platform xcb noalpha   | 18 ms       |
| Pi 3       | ./qt-rectangles -platform eglfs noalpha | 23 ms       |
| Pi Model B | ./qt-rectangles -platform xcb           | 96 ms       |
| Pi Model B | ./qt-rectangles -platform eglfs         | 422 ms      |
| Pi Model B | ./qt-rectangles -platform xcb noalpha   | 34 ms       |
| Pi Model B | ./qt-rectangles -platform eglfs noalpha | 65 ms       |

# Note to self

Make sure that the paths are right to the proper Qt versions. The easy way is to
compile one version of Qt with only eglfs support and the other version with
only xcb support. Then if you get the wrong library at runtime, the `-platform`
argument will result in an error. For example,

  QT_PLUGIN_PATH=~/qt-eglfs/plugins LD_LIBRARY_PATH=~/qt-eglfs/lib ./qt-rectangles
