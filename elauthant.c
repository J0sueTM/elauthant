#include "postgres.h"
#include "fmgr.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(auth_hello_world);
Datum auth_hello_world(PG_FUNCTION_ARGS) {
  PG_RETURN_TEXT_P(cstring_to_text("hello world"));
}
