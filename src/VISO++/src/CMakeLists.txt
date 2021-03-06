
# Eigen
#include_directories( "/usr/include/eigen3" )

find_package( Eigen3 REQUIRED )
include_directories( ${EIGEN3_INCLUDE_DIR} )

# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


# Sophus 
find_package( Sophus REQUIRED )
include_directories( ${Sophus_INCLUDE_DIRS} )



# g2o


add_library(libviso2 
    filter.cpp
    GroundTruth.cpp
    matcher.cpp
    matrix.cpp
    reconstruction.cpp
    triangle.cpp
    viso.cpp
    viso_mono.cpp
    viso_stereo.cpp
    )
target_link_libraries(libviso2 ${OpenCV_LIBS} png)


# for test
add_library(libtest 
    filter.cpp
    matcher.cpp
    matrix.cpp
    triangle.cpp
    viso.cpp
    viso_mono.cpp
    viso_stereo.cpp
    config.cpp
    camera.cpp
    converter.cpp
    frame.cpp
    )
target_link_libraries(libtest
    png
    ${Sophus_LIBRARIES}
    ${OpenCV_LIBS}
    ${PROJECT_SOURCE_DIR}/Thirdparty/DBoW2/lib/libDBoW2.so
    ${PROJECT_SOURCE_DIR}/Thirdparty/g2o/lib/libg2o.so
    )



add_executable(viso2_plus demo.cpp )
target_link_libraries(viso2_plus libviso2 png ${OpenCV_LIBS})
