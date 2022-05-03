add_library(shapes INTERFACE)
target_include_directories(shapes INTERFACE include/)
target_link_libraries(shapes INTERFACE draw_gtk)
target_link_libraries(shapes INTERFACE logger)
