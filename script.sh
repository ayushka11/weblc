SRC_FILE="FINAL/VM/lc3_PUREC_.c"
OUTPUT_FILE="src/add.mjs"
EXPORT_NAME="createModule"

emcc --no-entry "$SRC_FILE" -o "$OUTPUT_FILE" \
  -s ENVIRONMENT="web" \
  -s SINGLE_FILE=1 \
  -s EXPORT_NAME="$EXPORT_NAME" \
  -s USE_ES6_IMPORT_META=0 \
  -s EXPORTED_FUNCTIONS='["_ok","_print_registers", "_single_instruction", "_malloc", "_free"]' \
  -s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' \
  --preload-file "FINAL/VM/program" \
  --embed-file "FINAL/VM/memory.mem" \
  --embed-file "FINAL/VM/register.mem" \
  -o "FINAL/VM/willwork.html"
