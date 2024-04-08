file(GLOB_RECURSE ALLFILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*)

add_executable(gilded_rose_tests ${ALLFILES})

target_link_libraries(gilded_rose_tests PRIVATE
        gilded_rose
        ApprovalTests::ApprovalTests
        Catch2::Catch2WithMain)
