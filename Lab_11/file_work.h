#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

extern int input_array(double* data, size_t size);

extern void write_to_file(const char* filename, const double* data, size_t size);

extern int read_from_file(const char* filename, double* buffer, size_t size);


extern void write_to_file_binary(const char* filename, const double* data, size_t size);

extern int read_from_file_binary(const char* filename, double* buffer, size_t size);

extern void rewrite_abs(const char* filename, const char* new_filename, double threshold);

#ifdef __cplusplus
}
#endif