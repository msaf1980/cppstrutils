set(SOURCES)
set(LIBRARIES)

# Scan dir for standart source files
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} strutils_SOURCES)

if(BUILD_SHARED_LIBS)
    add_library(strutils SHARED ${strutils_SOURCES})
    set_target_properties(
        concurrent
        PROPERTIES OUTPUT_NAME strutils
                   SOVERSION "0"
                   VERSION "0.1")
endif()
add_library(strutils_static STATIC ${strutils_SOURCES})
set_target_properties(strutils_static PROPERTIES OUTPUT_NAME strutils)
