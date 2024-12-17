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

function(generate_targets TARGET_DIR PREFIX)
    file(GLOB TARGET_SOURCES CONFIGURE_DEPENDS "${TARGET_DIR}/*.c")
    foreach(TARGET_SOURCE ${TARGET_SOURCES})
        get_filename_component(TARGET "${TARGET_SOURCE}" NAME_WE)
        string(REPLACE "_" "-" TARGET "${TARGET}")
        string(PREPEND TARGET "${PREFIX}")
        add_executable("${TARGET}")
        target_sources("${TARGET}" PRIVATE "${TARGET_SOURCE}")
        target_compile_features("${TARGET}" PRIVATE c_std_11)
    endforeach()
endfunction()

# Sources

generate_targets("${ISSP_EXAMPLES_DIR}" "example-")
generate_targets("${ISSP_EXERCISES_DIR}" "exercise-")
generate_targets("${ISSP_SOLUTIONS_DIR}" "solution-")
generate_targets("${ISSP_HACKMES_DIR}" "hackme-")
