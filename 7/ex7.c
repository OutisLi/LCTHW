#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
        int bugs = 100;
        double bug_rate = 1.2;

        printf("You have %d bugs at the imaginary rate of %f.\n",
               bugs, bug_rate);

        unsigned long un_long_max = ULONG_MAX;
        long s_long_max = LONG_MAX;

        printf("unsigned long max: %lu\n", un_long_max);
        printf("long max: %ld\n", s_long_max);

        unsigned long universe_of_defects = LONG_MAX * 2 + 2;
        printf("The entire universe has %lu bugs.\n",
               universe_of_defects);

        double expected_bugs = bugs * bug_rate;
        printf("You are expected to have %f bugs.\n",
               expected_bugs);

        double part_of_universe = expected_bugs / universe_of_defects;
        printf("That is only a %e portion of the universe.\n",
               part_of_universe);

        // this makes no sense, just a demo of something weird
        char nul_byte = '\0';
        int care_percentage = bugs * nul_byte;
        printf("Which means you should care %d%%.\n",
               care_percentage);
        printf("nul_byte: %c\n", nul_byte);

        char test = 'A';
        printf("test: %d\n", test);
        int test2 = 92;
        printf("test2: %c\n", test2);

        return 0;
}
