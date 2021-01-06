project(hidscripts)

add_library(${PROJECT_NAME} src/HIDScriptNode.cpp)

add_library(mod::hidscript ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/include
        )

target_link_libraries(${PROJECT_NAME} mod::node mod::state woled ${MULTITHREAD})