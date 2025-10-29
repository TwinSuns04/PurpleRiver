#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
sources = []
env.Append(CPPPATH=["src/"])
sources.append(Glob("src/*.cpp"))

env.Append(CPPPATH=["src/gdextension/"])
sources.append(Glob("src/gdextension/*.cpp"))

env.Append(CPPPATH=["src/map/"])
sources.append(Glob("src/map/*.cpp"))
env.Append(CPPPATH=["src/map/levels/"])
sources.append(Glob("src/map/levels/*.cpp"))
env.Append(CPPPATH=["src/map/procGen/"])
sources.append(Glob("src/map/procGen/*.cpp"))

env.Append(CPPPATH=["src/mechancis/"])
sources.append(Glob("src/mechanics/*.cpp"))

env.Append(CPPPATH=["src/player/"])
sources.append(Glob("src/player/*.cpp"))



library = env.SharedLibrary(
    "/home/garrett/GameDev_L/PurpleRiver_Main/PurpleRiver/purple-river/bin/libgdexample{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
    source=sources,
)

Default(library)


# Original SConsript file from Godot source below this point

#!/usr/bin/env python
#import os
#import sys

#env = SConscript("godot-cpp/SConstruct")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
#env.Append(CPPPATH=["src/"])
#sources = Glob("src/*.cpp")

#if env["platform"] == "macos":
#    library = env.SharedLibrary(
#        "demo/bin/libgdexample.{}.{}.framework/libgdexample.{}.{}".format(
#            env["platform"], env["target"], env["platform"], env["target"]
#        ),
#        source=sources,
#    )
#elif env["platform"] == "ios":
#    if env["ios_simulator"]:
#        library = env.StaticLibrary(
#            "demo/bin/libgdexample.{}.{}.simulator.a".format(env["platform"], env["target"]),
#            source=sources,
#        )
#    else:
#        library = env.StaticLibrary(
#           "demo/bin/libgdexample.{}.{}.a".format(env["platform"], env["target"]),
#            source=sources,
#        )
#else:
#    library = env.SharedLibrary(
#        "/home/garrett/GameDev_L/PurpleRiver_Main/PurpleRiver/purple-river/bin/libgdexample{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
#        source=sources,
#    )

#Default(library)
