
set (SFML_LIBS_FOUND "")

IF( DEFINED ENV{SFML_DIR} )
    SET( SFML_DIR "$ENV{SFML_DIR}" )
ENDIF()

FIND_LIBRARY(
    SFML_GRAPHICS_LIB
    NAMES sfml-graphics   
)

if (NOT SFML_GRAPHICS_LIB)
    message (FATAL_ERROR "sfml-graphics library not found !")
else()
    list(APPEND SFML_LIBS_FOUND "-lsfml-graphics")
    message ("sfml-graphics library :" ${SFML_GRAPHICS_LIB})
endif()

FIND_LIBRARY(
    SFML_WINDOW_LIB
    NAMES sfml-window   
)

if (NOT SFML_WINDOW_LIB)
    message (FATAL_ERROR "sfml-window library not found !")
else()
    list(APPEND SFML_LIBS_FOUND "-lsfml-window")
    message ("sfml-window library :" ${SFML_WINDOW_LIB})
endif()

FIND_LIBRARY(
    SFML_SYSTEM_LIB
    NAMES sfml-system
)

if (NOT SFML_SYSTEM_LIB)
    message (FATAL_ERROR "sfml-system library not found !")    
else()
    message ("sfml-system library :" ${SFML_SYSTEM_LIB})
    list(APPEND SFML_LIBS_FOUND "-lsfml-system")
endif()
message ("${SFML_LIBS_FOUND}")
target_link_libraries(particle PRIVATE ${SFML_LIBS_FOUND})




# find_package_handle_standard_args( SFML "SFML not found " SFML_LIBRARIES)