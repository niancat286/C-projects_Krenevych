#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

    extern void input_to_file_until_zero(const char* filename);
    extern int read_from_file_binary(const char* filename, int* buffer, size_t size);
    extern void write_to_file_binary(const char* filename, const int* data, size_t size);
    extern void filter_fibonacci(const char* src_filename, const char* dst_filename);

#ifdef __cplusplus
}
#endif
