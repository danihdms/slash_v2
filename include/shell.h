#ifndef SHELL_H
#define SHELL_H

#define PATH_MAX 1024
#define PROMPT_MAX 50

static char owd[PATH_MAX];
static char cwd[PATH_MAX];
static char dest[PATH_MAX];
static char prompt[PROMPT_MAX];
static int status = 0;

char *get_cwd();

char *get_owd();

char *get_dest();

char *get_prompt();

int get_status();

#define RESET_COLOR "\001\033[00m\002"

typedef enum {
    GREEN,
    RED,
    BLUE,
    CYAN,
    YELLOW, // or brown
    WHITE, // or gray
    BLACK,
    PURPLE,
} color;

void update_prompt(char *pr, char *cwd);

char *to_fg_color(color c);

char *to_bg_color(color c);

int pwd(char *c, char *cwd);

int cd(char **args, char *cwd, char *pwd, char *dest);

#endif