add_library(StarInput StarInput.cxx)

install(TARGETS StarInput
        RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib)
