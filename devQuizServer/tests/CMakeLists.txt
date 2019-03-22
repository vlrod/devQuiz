file( GLOB_RECURSE devQuizServer_SRCS *.cpp *.h )

set( devQuizServer_SRCS ${devQuizServer_SRCS} )

# Create the application
add_executable(devquizTest ${devQuizServer_SRCS} )

# Link to Cutelyst
target_link_libraries(devquizTest
    devQuizServer
    Qt5::Core
    Qt5::Network
    Qt5::Test
)
