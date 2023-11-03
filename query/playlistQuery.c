//
// Created by laphv on 9/1/2023.
//

#include "playlistQuery.h"
#include "models/userModel.h"
#include "models/listOfSong.h"
#include "utils/sys.h"

void listPlaylist()
{
    sqlite3 *db;
    char *errMsg = 0;

    // Mở kết nối tới cơ sở dữ liệu SQLite
    int rc = sqlite3_open("musicStorage.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Không thể mở kết nối tới cơ sở dữ liệu: %s\n", sqlite3_errmsg(db));
    }

    // Chuỗi truy vấn SQL
    const char *sql = "SELECT namePlaylist FROM playlists WHERE userInit = ?";

    // Chuẩn bị câu lệnh SQL
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Lỗi chuẩn bị câu lệnh truy vấn: %s\n", sqlite3_errmsg(db));
    }

    // Thiết lập giá trị tham số
    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);

    // Thực hiện truy vấn
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        char *name = sqlite3_column_text(stmt, 0);
        char *nameString = g_strdup((const char *)name);
        addNewSong(nameString);
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Lỗi truy vấn: %s\n", sqlite3_errmsg(db));
    }

    // Giải phóng tài nguyên
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

int checkPlaylistInDatabase(char namePlaylist[], char userInit[])
{
    sqlite3 *db;
    sqlite3_stmt *stmt;

    // Mở kết nối tới cơ sở dữ liệu SQLite
    int rc = sqlite3_open("musicStorage.db", &db);
    if (rc != SQLITE_OK) {
        printf("Can not open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    const char *sql = "SELECT COUNT(*) FROM playlists WHERE namePlaylist = ? AND userInit = ?";


    // Chuẩn bị truy vấn
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        printf("Lỗi chuẩn bị truy vấn: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Gán tham số vào truy vấn
    sqlite3_bind_text(stmt, 1, namePlaylist, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, userInit, -1, SQLITE_STATIC);

    // Thực thi truy vấn
    rc = sqlite3_step(stmt);


    if (rc == SQLITE_ROW) {
        int count = sqlite3_column_int(stmt, 0);
        if (count > 0) {
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return FAIL;
        } else {
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return OK;
        }
    } else {
        printf("Lỗi thực thi truy vấn: %s\n", sqlite3_errmsg(db));
    }

    // Giải phóng truy vấn và đóng kết nối cơ sở dữ liệu

}

int addPlaylistToDatabase(char namePlaylist[], char userInit[])
{
    sqlite3 *db;
    char *err_msg = 0;

    // Mở kết nối tới cơ sở dữ liệu
    int rc = sqlite3_open("musicStorage.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot connect to database: %s\n", sqlite3_errmsg(db));
        return FAIL;
    }

    // Chuỗi truy vấn
    const char *sql = "INSERT INTO playlists (playlistID, namePlaylist, quantitySong, userInit) "
                      "VALUES ((SELECT COALESCE(MAX(playlistID), 0) + 1 FROM playlists), '%s', '%d', '%s');";


    // Tạo và format truy vấn
    char query[512];
    sprintf(query, sql, namePlaylist,0,userInit);

    // Thực thi truy vấn
    rc = sqlite3_exec(db, query, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error in query: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return FAIL;
    }

    // Đóng kết nối tới cơ sở dữ liệu
    sqlite3_close(db);

    return OK;
}

int listPlaylistDetail()
{
    sqlite3 *db;
    char *errMsg = 0;

    // Mở kết nối tới cơ sở dữ liệu SQLite
    int rc = sqlite3_open("musicStorage.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Không thể mở kết nối tới cơ sở dữ liệu: %s\n", sqlite3_errmsg(db));
    }

    // Chuỗi truy vấn SQL
    const char *sql = "SELECT nameSong FROM playlistDetail WHERE namePlaylist = ?";

    // Chuẩn bị câu lệnh SQL
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Lỗi chuẩn bị câu lệnh truy vấn: %s\n", sqlite3_errmsg(db));
    }

    // Thiết lập giá trị tham số
    sqlite3_bind_text(stmt, 1, namePlaylist, -1, SQLITE_STATIC);

    // Thực hiện truy vấn
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        char *name = sqlite3_column_text(stmt, 0);
        char *nameString = g_strdup((const char *)name);
        addNewSong(nameString);
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Lỗi truy vấn: %s\n", sqlite3_errmsg(db));
    }

    // Giải phóng tài nguyên
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

int addSongToPlaylist(char namePlaylist[], char nameSong[])
{
    sqlite3 *db;
    char *err_msg = 0;

    // Mở kết nối tới cơ sở dữ liệu
    int rc = sqlite3_open("musicStorage.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot connect to database: %s\n", sqlite3_errmsg(db));
        return FAIL;
    }

    // Chuỗi truy vấn
    const char *sql = "INSERT INTO playlistDetail (namePlaylist, nameSong) "
                      "VALUES ('%s', '%s');";


    // Tạo và format truy vấn
    char query[512];
    sprintf(query, sql, namePlaylist,nameSong);

    // Thực thi truy vấn
    rc = sqlite3_exec(db, query, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error in query: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return FAIL;
    }

    // Đóng kết nối tới cơ sở dữ liệu
    sqlite3_close(db);

    return OK;
}

int checkSongInPlaylist(char namePlaylist[],char nameSong[])
{
    sqlite3 *db;
    char *err_msg = 0;
    int rc;

    // Mở kết nối đến CSDL
    rc = sqlite3_open("musicStorage.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot connect to database: %s\n", sqlite3_errmsg(db));
        return 1;
    }


    char sql[1000];
    sprintf(sql, "SELECT * FROM playlistDetail WHERE namePlaylist = '%s' AND nameSong = '%s';", namePlaylist, nameSong);

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Lỗi SQL: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return FAIL;
    }

    int result = 0;
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            result = 1; // Bài hát đã tồn tại trong CSDL
        }
    }

    sqlite3_finalize(stmt);

    if (result) {
        sqlite3_close(db);
        return OK;
    } else {
        sqlite3_close(db);
        return NO;
    }
}