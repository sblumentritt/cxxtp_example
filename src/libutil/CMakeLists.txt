# define/configure the target
# -------------------------------------
add_library(${${PROJECT_NAME}_target_libutil})
add_library(
    ${${PROJECT_NAME}_target_libutil}::${${PROJECT_NAME}_target_libutil}
    ALIAS
    ${${PROJECT_NAME}_target_libutil}
)

# use helper function to configure a target
include(utility/target_configuration)
configure_target(
    TARGET
        ${${PROJECT_NAME}_target_libutil}
    CXX_STANDARD
        17
    COMPILER_FLAGS
        "${${PROJECT_NAME}_cxx_compiler_flags}"
    SANITIZER_FLAGS
        "${${PROJECT_NAME}_sanitizer_flags}"
    LINKER_FLAGS
        "${${PROJECT_NAME}_linker_flags}"
    PUBLIC_INCLUDE_DIRS
        ${PROJECT_SOURCE_DIR}/include
    PRIVATE_INCLUDE_DIRS
        ${CMAKE_CURRENT_LIST_DIR}
        ${PROJECT_BINARY_DIR}
    BUILD_TYPE_AS_OUTPUT_DIR
    ENABLE_UNUSED_SECTION_GARBAGE_COLLECTION
)

# add analyzer to target
include(analyzer/clang_tidy)
register_for_clang_tidy(${${PROJECT_NAME}_target_libutil})

include(analyzer/cppcheck)
register_for_cppcheck(${${PROJECT_NAME}_target_libutil})

# strip binary for specific build types
include(utility/postbuild_strip_command)
add_postbuild_strip(${${PROJECT_NAME}_target_libutil})

# add source files and include sub-folder
# -------------------------------------
add_subdirectory(date_time)

# define installation configuration
# -------------------------------------
# use GNU standard locations
# NOTE: PREFIX=/usr/local/ by default
include(GNUInstallDirs)
install(
    TARGETS
        ${${PROJECT_NAME}_target_libutil}
    RUNTIME
        DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
