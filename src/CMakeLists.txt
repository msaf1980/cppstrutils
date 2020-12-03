set(SOURCES)
set(LIBRARIES)

# Scan dir for standart source files
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCES)

if(BUILD_SHARED_LIBS)
    add_library(${PROJECT} SHARED ${SOURCES})
    set_target_properties(
        concurrent
        PROPERTIES OUTPUT_NAME ${PROJECT}
                   SOVERSION "${VERSION_MAJOR}"
                   VERSION "${VERSION_STRING}")
endif()
add_library(${PROJECT}_static STATIC ${SOURCES})
set_target_properties(${PROJECT}_static PROPERTIES OUTPUT_NAME ${PROJECT})
