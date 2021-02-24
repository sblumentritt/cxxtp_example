# define/configure the target
# -------------------------------------
add_executable(${${PROJECT_NAME}_target_info_viewer})
add_executable(
    ${${PROJECT_NAME}_target_info_viewer}::${${PROJECT_NAME}_target_info_viewer}
    ALIAS
    ${${PROJECT_NAME}_target_info_viewer}
)

# use helper function to configure a target
include(utility/target_configuration)
configure_target(
    TARGET
        ${${PROJECT_NAME}_target_info_viewer}
    CXX_STANDARD
        17
    COMPILER_FLAGS
        "${${PROJECT_NAME}_cxx_compiler_flags}"
    SANITIZER_FLAGS
        "${${PROJECT_NAME}_sanitizer_flags}"
    LINKER_FLAGS
        "${${PROJECT_NAME}_linker_flags}"
    PRIVATE_INCLUDE_DIRS
        ${CMAKE_CURRENT_LIST_DIR}
        ${PROJECT_BINARY_DIR}
    BUILD_TYPE_AS_OUTPUT_DIR
    ENABLE_UNUSED_SECTION_GARBAGE_COLLECTION
)

# add analyzer to target
include(analyzer/clang_tidy)
register_for_clang_tidy(${${PROJECT_NAME}_target_info_viewer})

include(analyzer/cppcheck)
register_for_cppcheck(${${PROJECT_NAME}_target_info_viewer})

# strip binary for specific build types
include(utility/postbuild_strip_command)
add_postbuild_strip(${${PROJECT_NAME}_target_info_viewer})

# add source files and include sub-folder
# -------------------------------------
# target_sources(${${PROJECT_NAME}_target_info_viewer}
#     PRIVATE
#         # source file
# )

# link against dependencies
# -------------------------------------
# target_link_libraries(${${PROJECT_NAME}_target_info_viewer}
#     PRIVATE
#         # library
# )

# define installation configuration
# -------------------------------------
# use GNU standard locations
# NOTE: PREFIX=/usr/local/ by default
include(GNUInstallDirs)
install(
    TARGETS
        ${${PROJECT_NAME}_target_info_viewer}
    RUNTIME
        DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
