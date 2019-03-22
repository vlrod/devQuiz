file(GLOB_RECURSE devQuizServer_SRCS *.cpp *.h)

set(devQuizServer_SRCS
    ${devQuizServer_SRCS}
    ${TEMPLATES_SRC}
)

# Create the application
add_library(devQuizServer SHARED ${devQuizServer_SRCS})

# Link to Cutelyst and Qt
target_link_libraries(devQuizServer
    Cutelyst::Core
    Qt5::Core
    Qt5::Network
)

