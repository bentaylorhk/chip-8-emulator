# Benjamin Michael Taylor (bentaylorhk)
# 2023

function(create_target)
    set(options EXECUTABLE)
    set(oneValueArgs NAME LIB_TYPE)
    set(multiValueArgs SOURCES PRIVATE_LIBS PUBLIC_LIBS INCLUDES SYSTEM_INCLUDES DEFINES)

    cmake_parse_arguments(TARGET "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if (TARGET_NAME STREQUAL "")
        message(FATAL_ERROR "NAME must be defined in ${CMAKE_CURRENT_FUNCTION}")
    endif ()

    if (NOT TARGET_SOURCES)
        message(FATAL_ERROR "One or more source files must be added to ${CMAKE_CURRENT_FUNCTION}")
    endif ()

    if (TARGET_EXECUTABLE)
        if (TARGET_LIB_TYPE)
            message(FATAL_ERROR "LIB_TYPE must not be defined in ${CMAKE_CURRENT_FUNCTION} if executable")
        endif ()

        add_executable(${TARGET_NAME} ${TARGET_SOURCES})
    else ()
        if (TARGET_LIB_TYPE STREQUAL "")
            message(FATAL_ERROR "LIB_TYPE must be defined in ${CMAKE_CURRENT_FUNCTION} if not executable")
        endif ()

        add_library(${TARGET_NAME} ${TARGET_LIB_TYPE} ${TARGET_SOURCES})
    endif ()

    if (TARGET_PRIVATE_LIBS)
        target_link_libraries(${TARGET_NAME} PRIVATE ${TARGET_PRIVATE_LIBS})
    endif ()

    if (TARGET_PUBLIC_LIBS)
        target_link_libraries(${TARGET_NAME} PUBLIC ${TARGET_PUBLIC_LIBS})
    endif ()

    if (TARGET_INCLUDES)
        target_include_directories(${TARGET_NAME} PUBLIC ${TARGET_INCLUDES})
    endif ()

    if (TARGET_SYSTEM_INCLUDES)
        target_include_directories(${TARGET_NAME} SYSTEM PUBLIC ${TARGET_SYSTEM_INCLUDES})
    endif ()

    if (TARGET_DEFINES)
        target_compile_definitions(${TARGET_NAME} PUBLIC ${TARGET_DEFINES})
    endif ()
endfunction()