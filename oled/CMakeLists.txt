project(oled)

add_library(${PROJECT_NAME} src/DEV_Config.c
                            src/OLED_Driver.c
                            src/OLED_GUI.c)

add_library(mod::oled ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME} 
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} mod::fonts ${MULTITHREAD} ${WIREPI})