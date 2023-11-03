//
// Created by laphv on 8/27/2023.
//

#include "songQuery.h"
#include "models/listOfSong.h"
#include "models/userModel.h"
char nameOfItArtist[PATH_MAX];

void listExplorer()
{
    sqlite3 *db;
    char *errMsg = 0;

    // Mở kết nối tới cơ sở dữ liệu SQLite
    int rc = sqlite3_open("musicStorage.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Không thể mở kết nối tới cơ sở dữ liệu: %s\n", sqlite3_errmsg(db));
    }

    // Chuỗi truy vấn SQL
    const char *sql = "SELECT songName FROM songs";

    // Chuẩn bị câu lệnh SQL
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Lỗi chuẩn bị câu lệnh truy vấn: %s\n", sqlite3_errmsg(db));
    }

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

int artistName(char song[])
{
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int rc;
    const char *sql = "SELECT artistName FROM songs WHERE songName = ?";

    char *artist = NULL;

    // Mở cơ sở dữ liệu SQLite
    rc = sqlite3_open("musicStorage.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return FAIL;
    }

    // Chuẩn bị truy vấn
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
        return FAIL;
    }

    // Gán tham số cho truy vấn
    rc = sqlite3_bind_text(stmt, 1, song, -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot bind parameter: %s\n", sqlite3_errmsg(db));
        return FAIL;
    }

    // Thực thi truy vấn
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        // Lấy giá trị artist từ cột đầu tiên của dòng kết quả
        const unsigned char *result = sqlite3_column_text(stmt, 0);
        artist = strdup((const char*)result);
        strcpy(nameOfItArtist,artist);
        // Giải phóng tuyên bố
        sqlite3_finalize(stmt);

        // Đóng cơ sở dữ liệu SQLite
        sqlite3_close(db);
        return OK;
    } else if (rc != SQLITE_DONE) {
        fprintf(stderr, "Cannot execute query: %s\n", sqlite3_errmsg(db));
        // Giải phóng tuyên bố
        sqlite3_finalize(stmt);

        // Đóng cơ sở dữ liệu SQLite
        sqlite3_close(db);
        return FAIL;
    }



}

void listMySong()
{
    sqlite3 *db;
    char *errMsg = 0;

    // Mở kết nối tới cơ sở dữ liệu SQLite
    int rc = sqlite3_open("musicStorage.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Không thể mở kết nối tới cơ sở dữ liệu: %s\n", sqlite3_errmsg(db));
    }

    // Chuỗi truy vấn SQL
    const char *sql = "SELECT songName FROM songs WHERE userPost = ?";

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

int add_song(char name[],char artist[],char user[],int durationOfSong)
{

    sqlite3* db;
    sqlite3_stmt* stmt;
    char *err_msg = 0;
    int rc;
    rc = sqlite3_open("musicStorage.db", &db);
    if (rc != SQLITE_OK) {
        printf("Can not access to database: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return ADD_FAIL;
    }

    char* sql = "SELECT * FROM songs WHERE songName = ? ";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        printf("Error: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return ADD_FAIL;
    }

    // Thiết lập giá trị tham số cho truy vấn
    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);

    // Thực hiện truy vấn
    rc = sqlite3_step(stmt);

    //kiểm tra tài khoản đã tồn tại hay chưa
    if (rc == SQLITE_ROW)
    {
        sqlite3_finalize(stmt);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return ADD_FAIL;
    }
    else{

        // thêm account mới vào database
        char *insert_sql = sqlite3_mprintf("INSERT INTO songs (songID,songName,artistName,userPost,durationSong) VALUES ((SELECT COALESCE(MAX(songID), 0) + 1 FROM songs),'%s','%s','%s','%d');",
                                           name, artist, user,durationOfSong);
        rc = sqlite3_exec(db, insert_sql, 0, 0, &err_msg);
        if (rc != SQLITE_OK) {
            printf("SQL error: %s\n", err_msg);
            sqlite3_finalize(stmt);
            sqlite3_free(err_msg);
            sqlite3_close(db);
            return ADD_FAIL;
        } else{
            //copy_file();
            // đóng database
            sqlite3_finalize(stmt);
            sqlite3_free(err_msg);
            sqlite3_close(db);
            return ADD_OK;
        }
    }
}