add_library(container INTERFACE)
target_include_directories(container INTERFACE include/)

target_link_libraries(container INTERFACE shapes)
