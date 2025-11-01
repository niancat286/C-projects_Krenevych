#ifndef _POLYNOME_H_
#define _POLYNOME_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

    typedef struct Monome_ {
        int degree;
        double a;
    } Monome;

    typedef struct Polynome_ {
        int n;
        Monome* mon;
    } Polynome;

    extern int input_polynome(Polynome* p);

    extern void output_polynome(const Polynome* p);

    extern Polynome read_from_file(const char* fname);

    extern int write_to_file(const char* fname, const Polynome* p);

    extern void free_polynome(Polynome* p);

    extern Polynome derivative(const Polynome* p);

    extern int append_to_file(const char* fname, const Polynome* p);

    extern int replace_in_file(const char* fname, const Polynome* p);

#ifdef __cplusplus
}
#endif

#endif