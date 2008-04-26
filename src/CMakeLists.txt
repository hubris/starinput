set(SRC StarInput.cpp StarMouse.cpp)

set(HEADERS ../include/StarInput/StarInput.h
            ../include/StarInput/StarInputListener.h
            #../include/StarInput/StarKeyboardListener.h
            ../include/StarInput/StarMouse.h
            ../include/StarInput/StarMouseEvent.h
            ../include/StarInput/StarMouseInterface.h
            ../include/StarInput/StarMouseListener.h
            ../include/StarInput/StarMouseSDL.h
)

source_group(Headers\\StarInput FILES ${HEADERS})
source_group(Headers FILES ../include/StarInput.h)

add_library(StarInput ${SRC} ${HEADERS} ../include/StarInput.h)
target_link_libraries(StarInput ${SDL_LIBRARY})

install(TARGETS StarInput
        RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib)
