/*
** If the canonical build process finds the file
** sqlite3_wasm_extra_init.c in the main wasm build directory, it
** arranges to include that file in the build of sqlite3.wasm and
** defines SQLITE_EXTRA_INIT=sqlite3_wasm_extra_init.
**
** The C file must define the function sqlite3_wasm_extra_init() with
** this signature:
**
**  int sqlite3_wasm_extra_init(const char *)
**
** and the sqlite3 library will call it with an argument of NULL one
** time during sqlite3_initialize(). If it returns non-0,
** initialization of the library will fail.
*/

#include "sqlite3ext.h"

int create_rs_extension(
    sqlite3 *db,
    char **pzErrMsg,
    const sqlite3_api_routines *pApi);

int sqlite3_wasm_extra_init(const char *z)
{
    return sqlite3_auto_extension((void *)create_rs_extension);
}
