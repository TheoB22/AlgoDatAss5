 # Build tests


add_executable(Convex_Hull
Graham_Scan.cpp
matplotlibcpp.h
)

find_package(PythonLibs REQUIRED)
INCLUDE_DIRECTORIES( ${PYTHON_INCLUDE_DIRS} )
link_directories( ${PYTHON_LIBRARIES})
target_link_libraries( Convex_Hull ${PYTHON_LIBRARY})

