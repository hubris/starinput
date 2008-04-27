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

if(WIN32)
  set(SRC_DI8 StarInputDI8.cpp StarMouseDI8.cpp)
  set(HEADERS_DI8 ../include/StarInput/StarInputDI8.h
                  ../include/StarInput/StarMouseDI8.h)
endif(WIN32)

source_group(Headers\\StarInput FILES ${HEADERS} ${HEADERS_DI8})
source_group(Headers FILES ../include/StarInput.h)

add_library(StarInput ${SRC} ${HEADERS} ../include/StarInput.h ${HEADERS_DI8} ${SRC_DI8})
target_link_libraries(StarInput ${SDL_LIBRARY} ${DI8_LIB})

install(TARGETS StarInput
        RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib)
