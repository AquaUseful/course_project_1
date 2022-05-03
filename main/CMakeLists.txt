set(MAIN_EXECUTABLE_SOURCES
src/main.cpp)

add_executable(main ${MAIN_EXECUTABLE_SOURCES})
target_link_libraries(main PRIVATE shapes)
target_link_libraries(main PRIVATE logger)

target_link_libraries(main PRIVATE ${GTKMM_LIBRARIES})
