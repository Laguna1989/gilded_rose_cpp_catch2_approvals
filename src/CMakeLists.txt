file(GLOB_RECURSE ALLFILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*)

add_library(gilded_rose ${ALLFILES})

target_include_directories(gilded_rose PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
