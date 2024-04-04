SRC_FILE=FINAL/VM/lc3_EMSCRIPTEN.c
OUTPUT_FILE=src/add.mjs
EXPORT_NAME=createModule

emcc --no-entry $SRC_FILE -o $OUTPUT_FILE \
  -s ENVIRONMENT='web' \
  -s SINGLE_FILE=1 \
  -s EXPORT_NAME="$EXPORT_NAME" \
  -s USE_ES6_IMPORT_META=0 \
  -s EXPORTED_FUNCTIONS='["_execute", "_malloc", "_free"]' \
  -s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' \
  --embed-file FINAL/VM/memory.txt \
  --embed-file FINAL/VM/register.txt \
  -O3