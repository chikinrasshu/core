if (NOT TARGET cwalk)
    add_subdirectory("cwalk")
    add_library(cwalk::cwalk ALIAS cwalk)
endif()
