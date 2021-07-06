include(FetchContent)
FetchContent_Declare(
googletest
URL https://github.com/google/googletest/archive/355d57d90d9744c41ac7c99f1e960778f1c63040.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
add_definitions(-DEnableTests)

enable_testing()

target_sources(particle PRIVATE "./tests/basic_tests.cc")

target_link_libraries(
    particle
    PRIVATE
    gtest_main
    )

include(GoogleTest)
gtest_discover_tests(particle)