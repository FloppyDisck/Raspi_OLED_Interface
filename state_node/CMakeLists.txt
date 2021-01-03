project(states)

add_library(${PROJECT_NAME} src/StateItem.cpp)

add_library(mod::state ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/include
        )

target_link_libraries(${PROJECT_NAME} mod::node mod::oled ${MULTITHREAD} ${WIREPI})