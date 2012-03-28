CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)

PROJECT(TrafficControl)

ADD_EXECUTABLE( ${PROJECT_NAME} TrafficControl.cpp)

include_directories(/usr/lib/)

include_directories(/usr/include/opencv/)

set(opencv_libraries libcxcore.so libcv.so libhighgui.so libcvaux.so)

TARGET_LINK_LIBRARIES(TrafficControl ${opencv_libraries})

install(TARGETS TrafficControl DESTINATION share/applications)