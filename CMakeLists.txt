cmake_minimum_required(VERSION 3.8)

###########################
# CuckyGameEngine Options #
###########################
option(CGE_COMPILE_GLFW "Compile the GLFW backend" ON)

#########
# Setup #
#########

# Define project, source, and includes
project(CGE_Sample LANGUAGES CXX)

add_executable(CGE_Sample WIN32
	"Sample.cpp"
	"src/CGE/CuckyGameEngine.cpp"
	"src/CGE/Error.cpp"
	"src/CGE/Math.cpp"
)

target_include_directories(CGE_Sample PRIVATE "src")

# Force strict C++17
set_target_properties(CGE_Sample PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)

#######################
# CGE Backend Linking #
#######################
find_package(PkgConfig QUIET)

# Link and include GLFW backend
if(CGE_COMPILE_GLFW)
	# Include the backend code
	target_compile_definitions(CGE_Sample PRIVATE CGE_COMPILE_GLFW)
	target_sources(CGE_Sample PRIVATE "src/CGE/GLFW/Core.cpp")
	target_sources(CGE_Sample PRIVATE "src/CGE/GLFW/Render.cpp")
	
	# Link GLFW3
	find_package(GLFW3)
	if (PKG_CONFIG_FOUND)
		pkg_check_modules(glfw3 QUIET IMPORTED_TARGET glfw3)
	endif()
	target_compile_options(CGE_Sample PRIVATE ${glfw3_CFLAGS})
	target_link_libraries(CGE_Sample PRIVATE ${glfw3_LDFLAGS})
	
	# Link GLEW
	find_package(GLEW)
	if (PKG_CONFIG_FOUND)
		pkg_check_modules(glew QUIET IMPORTED_TARGET glew)
	endif()
	target_compile_options(CGE_Sample PRIVATE ${glew_CFLAGS})
	target_link_libraries(CGE_Sample PRIVATE ${glew_LDFLAGS})
endif()

# Include OpenGL base code if an OpenGL backend is used
if(CGE_COMPILE_GLFW)
	target_sources(CGE_Sample PRIVATE "src/CGE/OpenGL/Render.cpp")
endif()

##########
# Tweaks #
##########
# This is messy as hell, and has been replaced by CMAKE_MSVC_RUNTIME_LIBRARY,
# but that's a very recent CMake addition, so we're still doing it this way for now
if(MSVC AND MSVC_LINK_STATIC_RUNTIME)
	# Statically-link the CRT (vcpkg static libs do this)
	foreach(flag_var CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
		if(${flag_var} MATCHES "/MD")
			string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
		endif()
	endforeach()
endif()

# Do some other MSVC fixes
if(MSVC)
	# Disable warnings that normally fire up on MSVC when using "unsafe" functions instead of using MSVC's "safe" _s functions
	target_compile_definitions(CGE_Sample PRIVATE _CRT_SECURE_NO_WARNINGS)
	
	# Make it so source files are recognized as UTF-8 by MSVC
	target_compile_options(CGE_Sample PRIVATE "/utf-8")
	
	# Use `main` instead of `WinMain`
	set_target_properties(CGE_Sample PROPERTIES LINK_FLAGS "/ENTRY:mainCRTStartup")
endif()
