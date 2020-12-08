import qbs

Project {
    minimumQbsVersion: "1.7.1"

    CppApplication {
        consoleApplication: true

        cpp.cxxLanguageVersion: "c++14"

        property path graph_lib_dir: "C:/cOdzi/Practice/cpp/Graph_lib"

        files: [
            graph_lib_dir +"/Simple_window.h",
            graph_lib_dir +"/Point.h",
            graph_lib_dir +"/fltk.h",

            graph_lib_dir +"/Graph.h",
            graph_lib_dir +"/Graph.cpp",

            graph_lib_dir +"/GUI.h",
            graph_lib_dir +"/GUI.cpp",

            graph_lib_dir +"/Window.h",
            graph_lib_dir +"/Window.cpp",

            "main.cpp",

            "Constants.h",

            "Navig_win.h",
            "Navig_win.cpp",

            "add_point_win.h",
            "add_point_win.cpp",

            "town.h",
            "town.cpp",

            "road.h",
            "road.cpp",

            "Logics.h",
            "Logics.cpp",

            "Matrix.h",
            "Matrix.cpp",

            "axis.h",
            "axis.cpp",

            "test.h",
            "test.cpp"

        ]

        cpp.includePaths: "C:/cOdzi/Practice/cpp/fltk_win64/include"
        cpp.libraryPaths: "C:/cOdzi/Practice/cpp/fltk_win64/lib"
        cpp.cxxFlags: "-Wno-unused-parameter"
        cpp.driverLinkerFlags: "-mwindows"
        cpp.staticLibraries: [
            "fltk_images",
            "fltk",
            "fltk_png",
            "z",
            "fltk_jpeg",
            "ole32",
            "uuid",
            "comctl32",
        ]

        Group {     // Properties for the produced executable
            fileTagsFilter: "application"
            qbs.install: true
        }
    }
}
