cmake_minimum_required(VERSION 3.17)
project(music C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
find_library(SQLITE3_LIBRARY sqlite3 HINTS lib/)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})
find_library(MPG123_LIBRARIES NAMES mpg123)
include_directories(${MPG123_INCLUDE_DIRS})
find_library(MAGIC_LIBRARY magic)
find_path(MAGIC_INCLUDE_DIRS magic.h)


set(PROJECT_DIR ${PROJECT_SOURCE_DIR})
set(CMAKE_C_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(music main.c
        page/IntroPage.c
        page/IntroPage.h
        page/SignInPage.c
        page/SignInPage.h
        query/userQuery.c
        query/userQuery.h
        models/userModel.c
        models/userModel.h
        page/HomePage.c
        page/HomePage.h
        page/SignUpPage.c
        page/SignUpPage.h
        utils/loadTemp.c
        utils/loadTemp.h
        page/components/explorerTab.c
        page/components/explorerTab.h
        page/components/myMusicTab.c
        page/components/myMusicTab.h
        page/components/myPlaylistTab.c
        page/components/myPlaylistTab.h
        page/components/playTab.c
        page/components/playTab.h
        page/components/uploadTab.c
        page/components/uploadTab.h
        page/components/updatePlaylist.c
        page/components/updatePlaylist.h
        query/songQuery.c
        query/songQuery.h
        models/listOfSong.c
        models/listOfSong.h
        query/playlistQuery.c
        query/playlistQuery.h
        utils/filter.c
        utils/filter.h
        utils/upload.c
        utils/upload.h
        models/songModel.c
        models/songModel.h
        utils/control.c
        utils/control.h
        utils/sys.c
        utils/sys.h page/components/playlistDetail.c page/components/playlistDetail.h page/components/addToPlaylist.c page/components/addToPlaylist.h)

target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SQLITE3_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${MPG123_LIBRARIES})
include_directories(${MAGIC_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${MAGIC_LIBRARY})
