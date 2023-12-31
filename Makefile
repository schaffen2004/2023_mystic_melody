# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = L:\temp\Project\C\music

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = L:\temp\Project\C\music

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	"C:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe" -E echo "No interactive CMake dialog available."
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	"C:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe" --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start L:\temp\Project\C\music\CMakeFiles L:\temp\Project\C\music\CMakeFiles\progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start L:\temp\Project\C\music\CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named music

# Build rule for target.
music: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 music
.PHONY : music

# fast build rule for target.
music/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/build
.PHONY : music/fast

main.obj: main.c.obj

.PHONY : main.obj

# target to build an object file
main.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/main.c.obj
.PHONY : main.c.obj

main.i: main.c.i

.PHONY : main.i

# target to preprocess a source file
main.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/main.c.i
.PHONY : main.c.i

main.s: main.c.s

.PHONY : main.s

# target to generate assembly for a file
main.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/main.c.s
.PHONY : main.c.s

models/listOfSong.obj: models/listOfSong.c.obj

.PHONY : models/listOfSong.obj

# target to build an object file
models/listOfSong.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/models/listOfSong.c.obj
.PHONY : models/listOfSong.c.obj

models/listOfSong.i: models/listOfSong.c.i

.PHONY : models/listOfSong.i

# target to preprocess a source file
models/listOfSong.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/models/listOfSong.c.i
.PHONY : models/listOfSong.c.i

models/listOfSong.s: models/listOfSong.c.s

.PHONY : models/listOfSong.s

# target to generate assembly for a file
models/listOfSong.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/models/listOfSong.c.s
.PHONY : models/listOfSong.c.s

models/songModel.obj: models/songModel.c.obj

.PHONY : models/songModel.obj

# target to build an object file
models/songModel.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/models/songModel.c.obj
.PHONY : models/songModel.c.obj

models/songModel.i: models/songModel.c.i

.PHONY : models/songModel.i

# target to preprocess a source file
models/songModel.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/models/songModel.c.i
.PHONY : models/songModel.c.i

models/songModel.s: models/songModel.c.s

.PHONY : models/songModel.s

# target to generate assembly for a file
models/songModel.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/models/songModel.c.s
.PHONY : models/songModel.c.s

models/userModel.obj: models/userModel.c.obj

.PHONY : models/userModel.obj

# target to build an object file
models/userModel.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/models/userModel.c.obj
.PHONY : models/userModel.c.obj

models/userModel.i: models/userModel.c.i

.PHONY : models/userModel.i

# target to preprocess a source file
models/userModel.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/models/userModel.c.i
.PHONY : models/userModel.c.i

models/userModel.s: models/userModel.c.s

.PHONY : models/userModel.s

# target to generate assembly for a file
models/userModel.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/models/userModel.c.s
.PHONY : models/userModel.c.s

page/HomePage.obj: page/HomePage.c.obj

.PHONY : page/HomePage.obj

# target to build an object file
page/HomePage.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/HomePage.c.obj
.PHONY : page/HomePage.c.obj

page/HomePage.i: page/HomePage.c.i

.PHONY : page/HomePage.i

# target to preprocess a source file
page/HomePage.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/HomePage.c.i
.PHONY : page/HomePage.c.i

page/HomePage.s: page/HomePage.c.s

.PHONY : page/HomePage.s

# target to generate assembly for a file
page/HomePage.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/HomePage.c.s
.PHONY : page/HomePage.c.s

page/IntroPage.obj: page/IntroPage.c.obj

.PHONY : page/IntroPage.obj

# target to build an object file
page/IntroPage.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/IntroPage.c.obj
.PHONY : page/IntroPage.c.obj

page/IntroPage.i: page/IntroPage.c.i

.PHONY : page/IntroPage.i

# target to preprocess a source file
page/IntroPage.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/IntroPage.c.i
.PHONY : page/IntroPage.c.i

page/IntroPage.s: page/IntroPage.c.s

.PHONY : page/IntroPage.s

# target to generate assembly for a file
page/IntroPage.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/IntroPage.c.s
.PHONY : page/IntroPage.c.s

page/SignInPage.obj: page/SignInPage.c.obj

.PHONY : page/SignInPage.obj

# target to build an object file
page/SignInPage.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/SignInPage.c.obj
.PHONY : page/SignInPage.c.obj

page/SignInPage.i: page/SignInPage.c.i

.PHONY : page/SignInPage.i

# target to preprocess a source file
page/SignInPage.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/SignInPage.c.i
.PHONY : page/SignInPage.c.i

page/SignInPage.s: page/SignInPage.c.s

.PHONY : page/SignInPage.s

# target to generate assembly for a file
page/SignInPage.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/SignInPage.c.s
.PHONY : page/SignInPage.c.s

page/SignUpPage.obj: page/SignUpPage.c.obj

.PHONY : page/SignUpPage.obj

# target to build an object file
page/SignUpPage.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/SignUpPage.c.obj
.PHONY : page/SignUpPage.c.obj

page/SignUpPage.i: page/SignUpPage.c.i

.PHONY : page/SignUpPage.i

# target to preprocess a source file
page/SignUpPage.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/SignUpPage.c.i
.PHONY : page/SignUpPage.c.i

page/SignUpPage.s: page/SignUpPage.c.s

.PHONY : page/SignUpPage.s

# target to generate assembly for a file
page/SignUpPage.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/SignUpPage.c.s
.PHONY : page/SignUpPage.c.s

page/components/addToPlaylist.obj: page/components/addToPlaylist.c.obj

.PHONY : page/components/addToPlaylist.obj

# target to build an object file
page/components/addToPlaylist.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/addToPlaylist.c.obj
.PHONY : page/components/addToPlaylist.c.obj

page/components/addToPlaylist.i: page/components/addToPlaylist.c.i

.PHONY : page/components/addToPlaylist.i

# target to preprocess a source file
page/components/addToPlaylist.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/addToPlaylist.c.i
.PHONY : page/components/addToPlaylist.c.i

page/components/addToPlaylist.s: page/components/addToPlaylist.c.s

.PHONY : page/components/addToPlaylist.s

# target to generate assembly for a file
page/components/addToPlaylist.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/addToPlaylist.c.s
.PHONY : page/components/addToPlaylist.c.s

page/components/explorerTab.obj: page/components/explorerTab.c.obj

.PHONY : page/components/explorerTab.obj

# target to build an object file
page/components/explorerTab.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/explorerTab.c.obj
.PHONY : page/components/explorerTab.c.obj

page/components/explorerTab.i: page/components/explorerTab.c.i

.PHONY : page/components/explorerTab.i

# target to preprocess a source file
page/components/explorerTab.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/explorerTab.c.i
.PHONY : page/components/explorerTab.c.i

page/components/explorerTab.s: page/components/explorerTab.c.s

.PHONY : page/components/explorerTab.s

# target to generate assembly for a file
page/components/explorerTab.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/explorerTab.c.s
.PHONY : page/components/explorerTab.c.s

page/components/myMusicTab.obj: page/components/myMusicTab.c.obj

.PHONY : page/components/myMusicTab.obj

# target to build an object file
page/components/myMusicTab.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/myMusicTab.c.obj
.PHONY : page/components/myMusicTab.c.obj

page/components/myMusicTab.i: page/components/myMusicTab.c.i

.PHONY : page/components/myMusicTab.i

# target to preprocess a source file
page/components/myMusicTab.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/myMusicTab.c.i
.PHONY : page/components/myMusicTab.c.i

page/components/myMusicTab.s: page/components/myMusicTab.c.s

.PHONY : page/components/myMusicTab.s

# target to generate assembly for a file
page/components/myMusicTab.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/myMusicTab.c.s
.PHONY : page/components/myMusicTab.c.s

page/components/myPlaylistTab.obj: page/components/myPlaylistTab.c.obj

.PHONY : page/components/myPlaylistTab.obj

# target to build an object file
page/components/myPlaylistTab.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/myPlaylistTab.c.obj
.PHONY : page/components/myPlaylistTab.c.obj

page/components/myPlaylistTab.i: page/components/myPlaylistTab.c.i

.PHONY : page/components/myPlaylistTab.i

# target to preprocess a source file
page/components/myPlaylistTab.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/myPlaylistTab.c.i
.PHONY : page/components/myPlaylistTab.c.i

page/components/myPlaylistTab.s: page/components/myPlaylistTab.c.s

.PHONY : page/components/myPlaylistTab.s

# target to generate assembly for a file
page/components/myPlaylistTab.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/myPlaylistTab.c.s
.PHONY : page/components/myPlaylistTab.c.s

page/components/playTab.obj: page/components/playTab.c.obj

.PHONY : page/components/playTab.obj

# target to build an object file
page/components/playTab.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/playTab.c.obj
.PHONY : page/components/playTab.c.obj

page/components/playTab.i: page/components/playTab.c.i

.PHONY : page/components/playTab.i

# target to preprocess a source file
page/components/playTab.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/playTab.c.i
.PHONY : page/components/playTab.c.i

page/components/playTab.s: page/components/playTab.c.s

.PHONY : page/components/playTab.s

# target to generate assembly for a file
page/components/playTab.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/playTab.c.s
.PHONY : page/components/playTab.c.s

page/components/playlistDetail.obj: page/components/playlistDetail.c.obj

.PHONY : page/components/playlistDetail.obj

# target to build an object file
page/components/playlistDetail.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/playlistDetail.c.obj
.PHONY : page/components/playlistDetail.c.obj

page/components/playlistDetail.i: page/components/playlistDetail.c.i

.PHONY : page/components/playlistDetail.i

# target to preprocess a source file
page/components/playlistDetail.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/playlistDetail.c.i
.PHONY : page/components/playlistDetail.c.i

page/components/playlistDetail.s: page/components/playlistDetail.c.s

.PHONY : page/components/playlistDetail.s

# target to generate assembly for a file
page/components/playlistDetail.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/playlistDetail.c.s
.PHONY : page/components/playlistDetail.c.s

page/components/updatePlaylist.obj: page/components/updatePlaylist.c.obj

.PHONY : page/components/updatePlaylist.obj

# target to build an object file
page/components/updatePlaylist.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/updatePlaylist.c.obj
.PHONY : page/components/updatePlaylist.c.obj

page/components/updatePlaylist.i: page/components/updatePlaylist.c.i

.PHONY : page/components/updatePlaylist.i

# target to preprocess a source file
page/components/updatePlaylist.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/updatePlaylist.c.i
.PHONY : page/components/updatePlaylist.c.i

page/components/updatePlaylist.s: page/components/updatePlaylist.c.s

.PHONY : page/components/updatePlaylist.s

# target to generate assembly for a file
page/components/updatePlaylist.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/updatePlaylist.c.s
.PHONY : page/components/updatePlaylist.c.s

page/components/uploadTab.obj: page/components/uploadTab.c.obj

.PHONY : page/components/uploadTab.obj

# target to build an object file
page/components/uploadTab.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/uploadTab.c.obj
.PHONY : page/components/uploadTab.c.obj

page/components/uploadTab.i: page/components/uploadTab.c.i

.PHONY : page/components/uploadTab.i

# target to preprocess a source file
page/components/uploadTab.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/uploadTab.c.i
.PHONY : page/components/uploadTab.c.i

page/components/uploadTab.s: page/components/uploadTab.c.s

.PHONY : page/components/uploadTab.s

# target to generate assembly for a file
page/components/uploadTab.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/page/components/uploadTab.c.s
.PHONY : page/components/uploadTab.c.s

query/playlistQuery.obj: query/playlistQuery.c.obj

.PHONY : query/playlistQuery.obj

# target to build an object file
query/playlistQuery.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/query/playlistQuery.c.obj
.PHONY : query/playlistQuery.c.obj

query/playlistQuery.i: query/playlistQuery.c.i

.PHONY : query/playlistQuery.i

# target to preprocess a source file
query/playlistQuery.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/query/playlistQuery.c.i
.PHONY : query/playlistQuery.c.i

query/playlistQuery.s: query/playlistQuery.c.s

.PHONY : query/playlistQuery.s

# target to generate assembly for a file
query/playlistQuery.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/query/playlistQuery.c.s
.PHONY : query/playlistQuery.c.s

query/songQuery.obj: query/songQuery.c.obj

.PHONY : query/songQuery.obj

# target to build an object file
query/songQuery.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/query/songQuery.c.obj
.PHONY : query/songQuery.c.obj

query/songQuery.i: query/songQuery.c.i

.PHONY : query/songQuery.i

# target to preprocess a source file
query/songQuery.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/query/songQuery.c.i
.PHONY : query/songQuery.c.i

query/songQuery.s: query/songQuery.c.s

.PHONY : query/songQuery.s

# target to generate assembly for a file
query/songQuery.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/query/songQuery.c.s
.PHONY : query/songQuery.c.s

query/userQuery.obj: query/userQuery.c.obj

.PHONY : query/userQuery.obj

# target to build an object file
query/userQuery.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/query/userQuery.c.obj
.PHONY : query/userQuery.c.obj

query/userQuery.i: query/userQuery.c.i

.PHONY : query/userQuery.i

# target to preprocess a source file
query/userQuery.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/query/userQuery.c.i
.PHONY : query/userQuery.c.i

query/userQuery.s: query/userQuery.c.s

.PHONY : query/userQuery.s

# target to generate assembly for a file
query/userQuery.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/query/userQuery.c.s
.PHONY : query/userQuery.c.s

utils/control.obj: utils/control.c.obj

.PHONY : utils/control.obj

# target to build an object file
utils/control.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/utils/control.c.obj
.PHONY : utils/control.c.obj

utils/control.i: utils/control.c.i

.PHONY : utils/control.i

# target to preprocess a source file
utils/control.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/utils/control.c.i
.PHONY : utils/control.c.i

utils/control.s: utils/control.c.s

.PHONY : utils/control.s

# target to generate assembly for a file
utils/control.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/utils/control.c.s
.PHONY : utils/control.c.s

utils/filter.obj: utils/filter.c.obj

.PHONY : utils/filter.obj

# target to build an object file
utils/filter.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/utils/filter.c.obj
.PHONY : utils/filter.c.obj

utils/filter.i: utils/filter.c.i

.PHONY : utils/filter.i

# target to preprocess a source file
utils/filter.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/utils/filter.c.i
.PHONY : utils/filter.c.i

utils/filter.s: utils/filter.c.s

.PHONY : utils/filter.s

# target to generate assembly for a file
utils/filter.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/utils/filter.c.s
.PHONY : utils/filter.c.s

utils/loadTemp.obj: utils/loadTemp.c.obj

.PHONY : utils/loadTemp.obj

# target to build an object file
utils/loadTemp.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/utils/loadTemp.c.obj
.PHONY : utils/loadTemp.c.obj

utils/loadTemp.i: utils/loadTemp.c.i

.PHONY : utils/loadTemp.i

# target to preprocess a source file
utils/loadTemp.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/utils/loadTemp.c.i
.PHONY : utils/loadTemp.c.i

utils/loadTemp.s: utils/loadTemp.c.s

.PHONY : utils/loadTemp.s

# target to generate assembly for a file
utils/loadTemp.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/utils/loadTemp.c.s
.PHONY : utils/loadTemp.c.s

utils/sys.obj: utils/sys.c.obj

.PHONY : utils/sys.obj

# target to build an object file
utils/sys.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/utils/sys.c.obj
.PHONY : utils/sys.c.obj

utils/sys.i: utils/sys.c.i

.PHONY : utils/sys.i

# target to preprocess a source file
utils/sys.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/utils/sys.c.i
.PHONY : utils/sys.c.i

utils/sys.s: utils/sys.c.s

.PHONY : utils/sys.s

# target to generate assembly for a file
utils/sys.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/utils/sys.c.s
.PHONY : utils/sys.c.s

utils/upload.obj: utils/upload.c.obj

.PHONY : utils/upload.obj

# target to build an object file
utils/upload.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/utils/upload.c.obj
.PHONY : utils/upload.c.obj

utils/upload.i: utils/upload.c.i

.PHONY : utils/upload.i

# target to preprocess a source file
utils/upload.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/utils/upload.c.i
.PHONY : utils/upload.c.i

utils/upload.s: utils/upload.c.s

.PHONY : utils/upload.s

# target to generate assembly for a file
utils/upload.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\music.dir\build.make CMakeFiles/music.dir/utils/upload.c.s
.PHONY : utils/upload.c.s

# Help Target
help:
	@echo The following are some of the valid targets for this Makefile:
	@echo ... all (the default if no target is provided)
	@echo ... clean
	@echo ... depend
	@echo ... edit_cache
	@echo ... rebuild_cache
	@echo ... music
	@echo ... main.obj
	@echo ... main.i
	@echo ... main.s
	@echo ... models/listOfSong.obj
	@echo ... models/listOfSong.i
	@echo ... models/listOfSong.s
	@echo ... models/songModel.obj
	@echo ... models/songModel.i
	@echo ... models/songModel.s
	@echo ... models/userModel.obj
	@echo ... models/userModel.i
	@echo ... models/userModel.s
	@echo ... page/HomePage.obj
	@echo ... page/HomePage.i
	@echo ... page/HomePage.s
	@echo ... page/IntroPage.obj
	@echo ... page/IntroPage.i
	@echo ... page/IntroPage.s
	@echo ... page/SignInPage.obj
	@echo ... page/SignInPage.i
	@echo ... page/SignInPage.s
	@echo ... page/SignUpPage.obj
	@echo ... page/SignUpPage.i
	@echo ... page/SignUpPage.s
	@echo ... page/components/addToPlaylist.obj
	@echo ... page/components/addToPlaylist.i
	@echo ... page/components/addToPlaylist.s
	@echo ... page/components/explorerTab.obj
	@echo ... page/components/explorerTab.i
	@echo ... page/components/explorerTab.s
	@echo ... page/components/myMusicTab.obj
	@echo ... page/components/myMusicTab.i
	@echo ... page/components/myMusicTab.s
	@echo ... page/components/myPlaylistTab.obj
	@echo ... page/components/myPlaylistTab.i
	@echo ... page/components/myPlaylistTab.s
	@echo ... page/components/playTab.obj
	@echo ... page/components/playTab.i
	@echo ... page/components/playTab.s
	@echo ... page/components/playlistDetail.obj
	@echo ... page/components/playlistDetail.i
	@echo ... page/components/playlistDetail.s
	@echo ... page/components/updatePlaylist.obj
	@echo ... page/components/updatePlaylist.i
	@echo ... page/components/updatePlaylist.s
	@echo ... page/components/uploadTab.obj
	@echo ... page/components/uploadTab.i
	@echo ... page/components/uploadTab.s
	@echo ... query/playlistQuery.obj
	@echo ... query/playlistQuery.i
	@echo ... query/playlistQuery.s
	@echo ... query/songQuery.obj
	@echo ... query/songQuery.i
	@echo ... query/songQuery.s
	@echo ... query/userQuery.obj
	@echo ... query/userQuery.i
	@echo ... query/userQuery.s
	@echo ... utils/control.obj
	@echo ... utils/control.i
	@echo ... utils/control.s
	@echo ... utils/filter.obj
	@echo ... utils/filter.i
	@echo ... utils/filter.s
	@echo ... utils/loadTemp.obj
	@echo ... utils/loadTemp.i
	@echo ... utils/loadTemp.s
	@echo ... utils/sys.obj
	@echo ... utils/sys.i
	@echo ... utils/sys.s
	@echo ... utils/upload.obj
	@echo ... utils/upload.i
	@echo ... utils/upload.s
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 0
.PHONY : cmake_check_build_system

