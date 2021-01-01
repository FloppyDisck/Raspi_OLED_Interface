project(oled_lib)

add_library(${PROJECT_NAME} src/DEV_Config.c
                            src/OLED_Driver.c
                            src/OLED_GUI.c)

add_library(mod::oled ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME} 
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} ${MULTITHREAD} ${WIREPI})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/fonts ${CMAKE_BINARY_DIR}/oled/fonts)
