cmake_minimum_required(VERSION 3.12)

option(CGE_BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(CGE_COMPILE_GLFW "Enable the GLFW (OpenGL) backend" ON)

project(CuckyGameEngine VERSION 0.0 DESCRIPTION "Multi-backend game engine that provides interfaces for rendering, input, audio, etc." LANGUAGES CXX)

add_library(CuckyGameEngine
	"src/CGE/CuckyGameEngine.cpp"
	"src/CGE/Core.cpp"
	"src/CGE/Render.cpp"
	"src/CGE/Error.cpp"
	"src/CGE/Math.cpp"
	
	"include/CGE/CuckyGameEngine.h"
	"include/CGE/Core.h"
	"include/CGE/Render.h"
	"include/CGE/Error.h"
	"include/CGE/Math.h"
)

#######################
# CGE Backend Linking #
#######################
find_package(PkgConfig QUIET)

# Link and include GLFW backend
if(CGE_COMPILE_GLFW)
	# Include the backend code
	target_compile_definitions(CuckyGameEngine PRIVATE CGE_COMPILE_GLFW)
	target_sources(CuckyGameEngine PRIVATE	"src/CGE/GLFW/Core.cpp"
											"src/CGE/GLFW/Core.h"
											"src/CGE/GLFW/Render.cpp"
											"src/CGE/GLFW/Render.h")
	
	# Link GLFW3
	find_package(GLFW3)
	if (PKG_CONFIG_FOUND)
		pkg_check_modules(glfw3 QUIET IMPORTED_TARGET glfw3)
	endif()
	target_compile_options(CuckyGameEngine PRIVATE ${glfw3_CFLAGS})
	target_link_libraries(CuckyGameEngine PRIVATE ${glfw3_LDFLAGS})
	
	# Link GLEW
	find_package(GLEW)
	if (PKG_CONFIG_FOUND)
		pkg_check_modules(glew QUIET IMPORTED_TARGET glew)
	endif()
	target_compile_options(CuckyGameEngine PRIVATE ${glew_CFLAGS})
	target_link_libraries(CuckyGameEngine PRIVATE ${glew_LDFLAGS})
endif()

# Include OpenGL base code if an OpenGL backend is used
if(CGE_COMPILE_GLFW)
	target_sources(CuckyGameEngine PRIVATE	"src/CGE/OpenGL/Render.cpp"
											"src/CGE/OpenGL/Render.h")
endif()

####################
# Misc. settings
####################

# Include the public headers
target_include_directories(CuckyGameEngine PUBLIC
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	"$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

# Export symbols
include(GenerateExportHeader)
GENERATE_EXPORT_HEADER(CuckyGameEngine EXPORT_FILE_NAME "${CMAKE_BINARY_DIR}/export/CuckyGameEngine_export.h")
target_include_directories(CuckyGameEngine PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/export>")

set_target_properties(CuckyGameEngine PROPERTIES CXX_VISIBILITY_PRESET hidden VISIBILITY_INLINES_HIDDEN ON)

# Force strict C++17
set_target_properties(CuckyGameEngine PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)

# Silence Microsoft's stupid deprecations
if(MSVC)
	target_compile_definitions(CuckyGameEngine PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

# Group files by directory when using an IDE
get_target_property(CUCKYGAMEENGINE_SOURCES CuckyGameEngine SOURCES) 
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES CUCKYGAMEENGINE_SOURCES)


####################
# Install
####################

include(GNUInstallDirs)

# Install directories
install(TARGETS CuckyGameEngine
	EXPORT CuckyGameEngineTargets
	ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
	LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
	RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
	PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/CuckyGameEngine"
)

# Install `CuckyGameEngineConfig.cmake` and `CuckyGameEngineTargets.cmake`
install(EXPORT CuckyGameEngineTargets DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/CuckyGameEngine")

export(TARGETS CuckyGameEngine FILE "CuckyGameEngineTargets.cmake")

include(CMakePackageConfigHelpers)
configure_package_config_file(
	"CuckyGameEngineConfig.cmake.in"
	"CuckyGameEngineConfig.cmake"
	INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/CuckyGameEngine"
)

install(FILES "${CMAKE_BINARY_DIR}/CuckyGameEngineConfig.cmake" DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/CuckyGameEngine")

# pkg-config
if(DEFINED STATIC_LIBS)
	list(REMOVE_DUPLICATES STATIC_LIBS)
	foreach(ITEM ${STATIC_LIBS})
		set(PKG_CONFIG_STATIC_LIBS "${PKG_CONFIG_STATIC_LIBS} -l${ITEM}")
	endforeach()
endif()

configure_file("CuckyGameEngine.pc.in" "CuckyGameEngine.pc" @ONLY)
install(FILES "${CMAKE_BINARY_DIR}/CuckyGameEngine.pc" DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig")
