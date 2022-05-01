set(LOGGER_LIBRARY_SOURCES
src/Logger.cpp)

add_library(logger STATIC ${LOGGER_LIBRARY_SOURCES})
target_link_libraries(logger PUBLIC utils)

target_include_directories(logger PUBLIC include/)
