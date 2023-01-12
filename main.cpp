/**
 * \file main.c
 * \author Ivan Shipaev
 * \brief Test
 * */

 /*
 * In this problem, we will consider 13-digit numbers in the thirteen-decimal system (digits 0,1,2,3,4,5,6,7,8,9,A,B,C) with leading zeros.
 * For example, ABA98859978C0, 6789110551234, 0000007000000
 * We call a number beautiful if the sum of its first six digits is equal to the sum of the last six digits.
 * Example:
 * The number 0055237050A00 is beautiful because 0+0+5+5+2+3 = 0+5+0+A+0+0
 * The number 1234AB988BABA is ugly because 1+2+3+4+A+B != 8+8+B+A+B+A
 * A task:
 * write a C / C ++ program that prints to standard output the number of 13-digit beautiful numbers with leading zeros in the thirteenth number system.
 *
 */

#include <iostream>

#define BASE        13      /// Radix
#define NDIGIT_COMP 6       /// Number of characters left and right to compare
#define NDIGIT_SKIP 1       /// Number of characters to skip
#define MAX_SUM     ((BASE-1) * NDIGIT_COMP + 1)  /// Size array for combinations of different sums

static unsigned sums[MAX_SUM]; /// Array for combinations of different sums

/**
 * @brief Initialize array for combinations of different sums
 * @param iter - Nesting counter
 * @param cnt - Number of combinations
 */
void init_sums(unsigned iter, unsigned cnt)
{
    if (--iter) {
        for (unsigned i = 0; i < BASE; ++i)
            init_sums(iter, cnt + i);
    } else {
        for (unsigned i = 0; i < BASE; ++i)
            ++sums[cnt + i];
    }
}

int main()
{
    unsigned cnt_beautiful = 0;

    init_sums(NDIGIT_COMP, 0);

    for (unsigned i = 0; i < MAX_SUM; ++i) {
        cnt_beautiful += sums[i] * sums[i];
        // std::cout << "Sums[" << i << "] = " << sums[i] << std::endl;
    }

    for (unsigned i = 0; i < NDIGIT_SKIP; ++i)
        cnt_beautiful *= BASE;

    std::cout << "Beautiful count = " << cnt_beautiful << std::endl;
    std::cout << "For exit press Enter or Ctrl+C" << std::endl;

    std::getchar();

    return 0;
}
