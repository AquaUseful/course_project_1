set(DRAW_GTK_LIBRARY_SOURCES
src/ShapeWindow.cpp
src/DrawAdapter.cpp
src/ShapeDrawArea.cpp)

add_library(draw_gtk STATIC ${DRAW_GTK_LIBRARY_SOURCES})
target_include_directories(draw_gtk PUBLIC include/)

target_link_libraries(draw_gtk PUBLIC shapes)
target_link_libraries(draw_gtk PRIVATE ${GTKMM_LIBRARIES})
