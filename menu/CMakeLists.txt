project(menu_exec)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories( ${PROJECT_NAME} 
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} mod::node mod::state mod::hidscript woled ${MULTITHREAD})
