project(string_implementation)

add_library(${PROJECT_NAME}
    src/string.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        spdlog::spdlog
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    include
    ${PROJECT_BINARY_DIR}/include
  PRIVATE
    ${PROJECT_BINARY_DIR}/src
)
