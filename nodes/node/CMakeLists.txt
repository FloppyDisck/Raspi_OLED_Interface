project(node)

add_library(${PROJECT_NAME} src/ExitNode.cpp
                            src/MenuNode.cpp
                            src/Node.cpp)

add_library(mod::node ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME} 
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} woled ${MULTITHREAD})