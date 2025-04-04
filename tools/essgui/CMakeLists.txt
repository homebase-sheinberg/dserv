cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Release)

if(NOT DEFINED PROJECT_VERSION)
  set(PROJECT_VERSION 0.95)
endif()
project( essgui VERSION ${PROJECT_VERSION} DESCRIPTION "essgui app")

FIND_PACKAGE(FLTK REQUIRED NO-MODULE)
message("using FLTK libs: ${FLTK_LIBRARIES}")

include_directories( ${FLTK_INCLUDE_DIR} src ../include ../../../dlsh/src ../../../dlsh/src/lablib  )

if(WIN32)
    link_directories( c:/usr/local/lib/$ENV{VSCMD_ARG_TGT_ARCH} )
    set(LIBFLTK fltk.lib)
    set(LIBTCL tcl90.lib)
    set(LIBDLSH dlsh-static.lib)
    # set(LIBDLSH libdlsh.lib)
    # set(LIBDG dg.lib)
    set(LIBJANSSON jansson.lib)
    set(LIBTCLSTUB tclstub.lib)
    set(ZLIB zlibstatic.lib)
    set(LZ4LIB liblz4_static.lib)
    set(PDFLIB hpdf.lib)
    set(LIBJANSSON jansson.lib)
else()
    link_directories( /usr/local/lib )
    find_library(LIBZ z)
    find_library(LIBLZ4 NAMES "liblz4.a")
    find_library(LIBFLTK NAMES "libfltk.a")
    find_library(LIBFLTK_ZLIB NAMES "libfltk_z.a")
    find_library(LIBTCL "tcl9.0")
    set(LIBTCLSTUB "/usr/local/lib/libtclstub.a")
    set(LIBDLSH "dlsh-static")
    set(LIBPDF "/usr/local/lib/libhpdf.a")
    find_library(LIBJANSSON NAMES "libjansson.a")
endif()

include_directories( ../src ../../dlsh/src ../../dlsh/src/lablib )
link_directories( .. )
add_executable( essgui src/essgui.cxx src/setup_ui.cxx src/TclInterp.cxx src/Fl_Console.cxx src/Fl_DgTable.cxx src/linenoise-fltk.cxx src/mdns.c src/mdns_query.c src/fort.c src/b64.c src/Fl_OpDesk.cxx src/Fl_OpBox.cxx src/Fl_OpButton.cxx)

if(WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:libcmt gdiplus.lib  comctl32.lib  ws2_32.lib  gdiplus.lib  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib")
    target_link_libraries( essgui ${LIBFLTK} ${LIBFLTK_Z} ${PDFLIB} ${LZ4LIB} ${LIBTCL} ${LIBDLSH} ${ZLIB} ${TCLLIB} ${LIBTCLSTUB} ${LIBJANSSON} ${LIBDG} )
elseif(APPLE)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -weak_framework UniformTypeIdentifiers -weak_framework ScreenCaptureKit")
    target_link_libraries( essgui ${LIBFLTK} ${LIBFLTK_Z} ${LIBDLSH} ${LIBLAB} ${LIBPDF} ${LIBZ} ${LIBLZ4} ${LIBTCL} ${LIBTCLSTUB} ${LIBJANSSON})
else()
    target_link_libraries( essgui ${LIBFLTK} ${LIBFLTK_Z} ${LIBLAB} ${LIBDLSH} ${LIBPDF} ${LIBZ} ${LIBLZ4} ${LIBTCL} ${LIBTCLSTUB} ${LIBJANSSON} X11 Xext Xinerama Xfixes Xcursor Xft Xrender fontconfig pangoxft-1.0 pangoft2-1.0 pango-1.0 gobject-2.0 glib-2.0 harfbuzz freetype pangocairo-1.0 cairo gtk-3 gdk-3 gio-2.0 wayland-cursor wayland-client dbus-1 xkbcommon)
endif()

set(CPACK_PACKAGE_NAME essgui)
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "GUI app to go with dserv and related tools.")
set(CPACK_PACKAGE_CONTACT SheinbergLab)

set(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS ${LIBTCL})
include(InstallRequiredSystemLibraries)

if(WIN32)
    # TODO
elseif(APPLE)
    INSTALL(TARGETS essgui RUNTIME DESTINATION . COMPONENT essgui)
    set(CPACK_COMPONENTS_ALL essgui)
    set(CPACK_PACKAGE_VERSION_MAJOR "${dserv_VERSION_MAJOR}")
    set(CPACK_PACKAGE_VERSION_MINOR "${dserv_VERSION_MINOR}")
    set(CPACK_GENERATOR "DragNDrop")
else()
    INSTALL(TARGETS essgui RUNTIME)
    set(CPACK_PACKAGING_INSTALL_PREFIX "/usr/local")
    set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
    set(CPACK_DEBIAN_PACKAGE_DEPENDS "libevdev2, libpq5, zlib1g, yajl-tools, libx11-6, libxinerama1, libxfixes3, libxcursor1, libpango-1.0-0, libpangocairo-1.0-0, libgtk-3-0")
endif()

include(CPack)
