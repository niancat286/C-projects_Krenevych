#ifndef C_PROJECTS_KRENEVYCH_MOUNTS_H
#define C_PROJECTS_KRENEVYCH_MOUNTS_H




struct Mounts {
    char* name;
    int height;
};

extern void output_mounts(const struct Mounts* mounts);
extern int input_mounts(struct Mounts* mounts);

extern void free_mounts(struct Mounts* mounts);

extern void highestMount(struct Mounts* mounts, int n);
extern  int get_height_mount(const struct Mounts* mounts, int n,  char* name);


#endif //C_PROJECTS_KRENEVYCH_MOUNTS_H