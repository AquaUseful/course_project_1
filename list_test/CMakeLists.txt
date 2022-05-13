set(LIST_TEST_EXEC_SOURCES
src/list_test.cpp)

add_executable(list_test ${LIST_TEST_EXEC_SOURCES})

target_link_libraries(list_test PRIVATE shapes)
target_link_libraries(list_test PRIVATE container)
target_link_libraries(list_test PRIVATE logger)

target_link_libraries(list_test PRIVATE ${GTKMM_LIBRARIES})
