cmake_minimum_required(VERSION 3.24)
project(issp
        VERSION "0.1.0"
        DESCRIPTION "Exercises and lab material for the ISSP course."
        HOMEPAGE_URL "https://github.com/IvanoBilenchi/issp-c"
        LANGUAGES C)

# Cache variables

option(ISSP_SANITIZERS "Enable sanitizers." OFF)

# Directories

set(ISSP_PROJECT_DIR "${CMAKE_CURRENT_LIST_DIR}")
set(ISSP_EXAMPLES_DIR "${ISSP_PROJECT_DIR}/examples")
set(ISSP_EXERCISES_DIR "${ISSP_PROJECT_DIR}/exercises")
set(ISSP_SOLUTIONS_DIR "${ISSP_EXERCISES_DIR}/solutions")
set(ISSP_HACKMES_DIR "${ISSP_PROJECT_DIR}/hackmes")

# Target settings

set(ISSP_COMPILE_FEATURES c_std_11)

if(MSVC)
    set(ISSP_WARNING_OPTIONS /W4 /wd4200 /wd4996)
else()
    set(ISSP_WARNING_OPTIONS -Wall -Wextra)
    if(ISSP_SANITIZERS)
        set(ISSP_SANITIZER_OPTIONS "-fsanitize=address,undefined")
    endif()
endif()

# Sources

add_subdirectory("${ISSP_EXAMPLES_DIR}")
add_subdirectory("${ISSP_EXERCISES_DIR}")
