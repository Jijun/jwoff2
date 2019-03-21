cmake_minimum_required(VERSION 2.8)

project(jwoff2)

set(CMAKE_BUILD_TYPE Release)
find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES jwoff2.cc)

include_directories(
  ${JAVA_INCLUDE_PATH}
  ${JAVA_INCLUDE_PATH2})


# Find WOFF2 dependencies
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(WOFF2Dec)
if (NOT WOFF2DEC_FOUND)
    message(FATAL_ERROR "liwoff2dec is needed.")
endif ()
find_package(WOFF2Enc)
if (NOT WOFF2ENC_FOUND)
    message(FATAL_ERROR "liwoff2enc is needed.")
endif ()

add_library(jwoff2 SHARED ${SOURCE_FILES})
target_link_libraries(jwoff2  "${WOFF2ENC_LIBRARIES}" "${WOFF2DEC_LIBRARIES}")

# jar build
find_package(Java REQUIRED)
include(UseJava)
set(CMAKE_JAVA_COMPILE_FLAGS "-source" "1.8" "-target" "1.8")
# Build the Java code into libjwoff2.jar
set(CMAKE_JAVA_JAR_ENTRY_POINT com.typoface.jwoff2.Main) 
add_jar(libjwoff2 SOURCES 
	${CMAKE_CURRENT_SOURCE_DIR}/src/java/com/typoface/jwoff2/WOFF2.java 
	${CMAKE_CURRENT_SOURCE_DIR}/src/java/com/typoface/jwoff2/Main.java 
	 ENTRY_POINT ${CMAKE_JAVA_JAR_ENTRY_POINT}
	)
get_target_property(_jarFile libjwoff2 JAR_FILE)
get_target_property(_classDir libjwoff2 CLASSDIR)
message(STATUS "Jar file ${_jarFile}")
message(STATUS "Class compiled to ${_classDir}")