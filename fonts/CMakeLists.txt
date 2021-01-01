project(fonts_lib)

add_library(${PROJECT_NAME} src/font8.c
                            src/font12.c
                            src/font16.c
                            src/font20.c
                            src/font24.c)

add_library(mod::fonts ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME} 
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} ${MULTITHREAD} ${WIREPI})