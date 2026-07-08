#include <stdio.h>

#include "cum.h"
#include "flag.h"

int
main(int argc, char **argv)
{
        const char *out_name;
        flag_program(.help = "~ mocc: My Own C Compiler by Hugo Coto", .positionals = flag_list("program"));
        flag_add(&out_name, "-o", "--out", .help = "Set output filename", .defaults = "a.out");

        if (flag_parse(&argc, &argv)) {
                flag_show_help(STDOUT_FILENO);
                exit(1);
        }

        Let program = argv[1];
        printf("Hello from mocc! Program=%s\n", program);

        flag_free();
        return 0;
}
