add_library(StarInput StarInput.cxx)
target_link_libraries(StarInput ${SDL_LIBRARY})

install(TARGETS StarInput
        RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib)
