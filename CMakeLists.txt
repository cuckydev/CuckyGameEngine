cmake_minimum_required(VERSION 3.8)

#########
# Setup #
#########

# Define project, source, and includes
project(CGE_Sample LANGUAGES CXX)

add_executable(CGE_Sample WIN32
	"Sample.cpp"
)

target_include_directories(CGE_Sample PRIVATE "src")

# Force strict C++17
set_target_properties(CGE_Sample PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)

########################
# Link CuckyGameEngine #
########################
set(CGE_BUILD_SHARED_LIBS OFF)
if(MSVC)
	set(LIBC ON CACHE INTERNAL "" FORCE)	# Needed to prevent possible 'symbol already defined' errors
endif()
add_subdirectory("src" EXCLUDE_FROM_ALL)
target_link_libraries(CGE_Sample PRIVATE CuckyGameEngine)

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
