# qt-rectangles

This is a simple test program to demonstrate performance differences on the
Raspberry Pi.

To run:

    qmake qt-rectangles.pro
    make
    ./qt-rectangles

# Measurements

Key:
xcb = X11 w/ OpenGL ES
eglfs = Full screen OpenGL ES (no X11)
linuxfb = Full screen software rendered
See http://doc.qt.io/qt-5/embedded-linux.html

noalpha = No alpha blending of rectangles

| Platform   | Commandline                             | Redraw time |
|------------|-----------------------------------------|-------------|
| Pi 3       | ./qt-rectangles -platform xcb           | 29 ms       |
| Pi 3       | ./qt-rectangles -platform eglfs         | 133 ms      |
| Pi 3       | ./qt-rectangles -platform xcb noalpha   | 18 ms       |
| Pi 3       | ./qt-rectangles -platform eglfs noalpha | 23 ms       |
| Pi Model B | ./qt-rectangles -platform xcb           | 96 ms       |
| Pi Model B | ./qt-rectangles -platform linuxfb       | 94 ms       |
| Pi Model B | ./qt-rectangles -platform eglfs         | 422 ms      |
| Pi Model B | ./qt-rectangles -platform xcb noalpha   | 34 ms       |
| Pi Model B | ./qt-rectangles -platform linuxfb noalpha | 36 ms       |
| Pi Model B | ./qt-rectangles -platform eglfs noalpha | 65 ms       |

# Notes to self

## Compiling the eglfs version of Qt 5

1. Download [qtbase-opensource-src-5.6.1-1.tar.xz](http://download.qt.io/official_releases/qt/5.6/5.6.1-1/submodules/qtbase-opensource-src-5.6.1-1.tar.xz) and
untar it on the Raspberry Pi.

2. Copy [qmake.conf](assets/qmake.conf) to `$QT/mkspecs/linux-g++`

3. Uninstall any X11 dev libraries. They seemed to confuse Qt's `./configure`
   script and since I didn't want them to link in anyway, I removed them. This
   was a manual process of running `apt list --installed | grep -- -dev`,
   looking for the X11 ones and then uninstalling them.

4. Run `./configure  -eglfs -no-xcb -no-xcb-xlib -no-nis -opensource -confirm-license -no-qml-debug -no-linuxfb -no-gif -opengl es2 -no-pch`
   (See log at bottom)

5. Run `make`

6. Come back tomorrow

## Running

Make sure that the paths are right to the proper Qt versions. The easy way is to
compile one version of Qt with only eglfs support and the other version with
only xcb support. Then if you get the wrong library at runtime, the `-platform`
argument will result in an error. I.e., do this:

  QT_PLUGIN_PATH=~/qt-eglfs/plugins LD_LIBRARY_PATH=~/qt-eglfs/lib ./qt-rectangles -platform eglfs

To get an xcb version of Qt5 quickly, run `sudo apt-get install qt5-default`

## Qt's ./configure log for enabling eglfs

```
$ ./configure  -eglfs -no-xcb -no-xcb-xlib -no-nis -opensource -confirm-license
-no-qml-debug -no-linuxfb -no-gif -opengl es2 -no-pch

This is the Qt Open Source Edition.

You are licensed to use this software under the terms of
the Lesser GNU General Public License (LGPL) versions 2.1.
You are also licensed to use this software under the terms of
the GNU Lesser General Public License (LGPL) versions 3.

You have already accepted the terms of the Open Source license.

Running configuration tests (phase 1)...
Done running configuration tests.
Creating qmake...
.............................................................................Done.
Running configuration tests (phase 2)...
Done running configuration tests.

   Configure summary

Build type:    linux-g++ (arm, CPU features: none detected)
Platform notes:

            - Also available for Linux: linux-clang linux-kcc linux-icc
              linux-cxx

Build options:
  Configuration .......... accessibility audio-backend c++11 c++14 clock-gettime
clock-monotonic compile_examples concurrent dbus dbus-linked egl eglfs
eglfs_brcm enable_new_dtags evdev eventfd fontconfig full-config getaddrinfo
getifaddrs harfbuzz iconv icu inotify ipv6ifname large-config largefile libudev
medium-config minimal-config mremap no-gif no-qml-debug opengl opengles2 openvg
pcre png posix_fallocate qpa qpa reduce_exports release rpath shared
small-config system-freetype system-jpeg system-png system-zlib
threadsafe-cloexec use_gold_linker
  Build parts ............ libs tools examples
  Mode ................... release
  Using sanitizer(s)...... none
  Using C++ standard ..... c++14
  Using gold linker....... yes
  Using new DTAGS ........ yes
  Using PCH .............. no
  Using LTCG ............. no
  Target compiler supports:
    Neon ................. no

Qt modules and options:
  Qt D-Bus ............... yes (linked to dbus-1)
  Qt Concurrent .......... yes
  Qt GUI ................. yes
  Qt Widgets ............. yes
  Large File ............. yes
  QML debugging .......... no
  Use system proxies ..... no

Support enabled for:
  Accessibility .......... yes
  ALSA ................... no
  CUPS ................... no
  Evdev .................. yes
  FontConfig ............. yes
  FreeType ............... yes (system library)
  Glib ................... no
  GStreamer .............. no
  GTK theme .............. no
  HarfBuzz ............... yes (bundled copy)
  Iconv .................. yes
  ICU .................... yes
  Image formats:
    GIF .................. no
    JPEG ................. yes (plugin, using system library)
    PNG .................. yes (in QtGui, using system library)
  libinput................ no
  Logging backends:
    journald ............... no
    syslog   ............... no
  mtdev .................. no
  Networking:
    getaddrinfo .......... yes
    getifaddrs ........... yes
    IPv6 ifname .......... yes
    libproxy.............. no
    OpenSSL .............. no
  NIS .................... no
  OpenGL / OpenVG:
    EGL .................. yes
    OpenGL ............... yes (OpenGL ES 2.0+)
    OpenVG ............... yes-auto
  PCRE ................... yes (bundled copy)
  pkg-config ............. yes
  PulseAudio ............. no
  QPA backends:
    DirectFB ............. no
    EGLFS ................ yes
      EGLFS i.MX6 ........ no
      EGLFS i.MX6 Wayland. no
      EGLFS EGLDevice .... no
      EGLFS GBM .......... no
      EGLFS Mali ......... no
      EGLFS Raspberry Pi . yes
      EGLFS X11 .......... no
    LinuxFB .............. no
    Mir client............ no
    XCB .................. no
  Session management ..... yes
  SQL drivers:
    DB2 .................. no
    InterBase ............ no
    MySQL ................ no
    OCI .................. no
    ODBC ................. no
    PostgreSQL ........... no
    SQLite 2 ............. no
    SQLite ............... yes (plugin, using bundled copy)
    TDS .................. no
  tslib .................. no
  udev ................... yes
  xkbcommon-x11........... no
  xkbcommon-evdev......... no
  zlib ................... yes (system library)


NOTE: Qt is using double for qreal on this system. This is binary incompatible
against Qt 5.1.
Configure with '-qreal float' to create a build that is binary compatible with
5.1.

Qt is now configured for building. Just run 'make'.
Once everything is built, you must run 'make install'.
Qt will be installed into /usr/local/Qt-5.6.1

Prior to reconfiguration, make sure you remove any leftovers from
the previous build.
```
