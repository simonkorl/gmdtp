#define ERROR 0
#define WARN 1
#define INFO 2
#define DEBUG 3
#define TRACE 4

static int LOG_LEVEL = 3;
static int LOG_COLOR = 0;

#define HELPER_LOG stdout
#define HELPER_OUT stdout

// log helper macro, no need to use \n
#define log(level, ...)                                                        \
  do {                                                                         \
    switch (level) {                                                           \
    case ERROR:                                                                \
      LOG_COLOR ? fprintf(HELPER_LOG, "\x1b[31m[ERROR] %s: ", __func__)        \
                : fprintf(HELPER_LOG, "[ERROR] %s: ", __func__);               \
      break;                                                                   \
    case WARN:                                                                 \
      LOG_COLOR ? fprintf(HELPER_LOG, "\x1b[33m[WARN ] %s: ", __func__)        \
                : fprintf(HELPER_LOG, "[WARN ] %s: ", __func__);               \
      break;                                                                   \
    case INFO:                                                                 \
      LOG_COLOR ? fprintf(HELPER_LOG, "\x1b[34m[INFO ] %s: ", __func__)        \
                : fprintf(HELPER_LOG, "[INFO ] %s: ", __func__);               \
      break;                                                                   \
    case DEBUG:                                                                \
      LOG_COLOR ? fprintf(HELPER_LOG, "\x1b[96m[DEBUG] %s: ", __func__)        \
                : fprintf(HELPER_LOG, "[DEBUG] %s: ", __func__);               \
      break;                                                                   \
    case TRACE:                                                                \
      LOG_COLOR ? fprintf(HELPER_LOG, "\x1b[90m[TRACE] %s: ", __func__)        \
                : fprintf(HELPER_LOG, "[TRACE] %s: ", __func__);               \
      break;                                                                   \
    }                                                                          \
    fprintf(HELPER_LOG, __VA_ARGS__);                                          \
    LOG_COLOR ? fprintf(HELPER_LOG, "\x1b[0m\n") : fprintf(HELPER_LOG, "\n");  \
    fflush(NULL);                                                              \
  } while (0)

#define log_error(...)                                                         \
  if (LOG_LEVEL > ERROR) {                                                     \
    log(ERROR, __VA_ARGS__);                                                   \
  } else

#define log_warn(...)                                                          \
  if (LOG_LEVEL > WARN) {                                                      \
    log(WARN, __VA_ARGS__);                                                    \
  } else

#define log_info(...)                                                          \
  if (LOG_LEVEL > INFO) {                                                      \
    log(INFO, __VA_ARGS__);                                                    \
  } else

#define log_debug(...)                                                         \
  if (LOG_LEVEL > DEBUG) {                                                     \
    log(DEBUG, __VA_ARGS__);                                                   \
  } else

#define log_trace(...)                                                         \
  if (LOG_LEVEL > TRACE) {                                                     \
    log(TRACE, __VA_ARGS__);                                                   \
  } else

// write what we cared into file
#define dump_file(...)                                                         \
  do {                                                                         \
    fprintf(HELPER_OUT, __VA_ARGS__);                                          \
    fflush(NULL);                                                              \
  } while (0)

#define dump_info(...)                                                         \
  do {                                                                         \
    fprintf(HELPER_OUT, __VA_ARGS__);                                          \
  } while (0);                                                                 \
  if (LOG_LEVEL > INFO) {                                                      \
    log(INFO, __VA_ARGS__);                                                    \
  }                                                                            \
  fflush(NULL);
