#include <stdio.h>
#include <time.h>
#include <sys/resource.h>

unsigned long long fibonacci(unsigned int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    while (b != 0) {
        unsigned long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    printf("Profiling Fibonacci & GCD(F(n), F(n-1))\n");
    printf("------------------------------------------------------------\n");
    printf("%-5s | %-12s | %-5s | %-12s | %-10s\n", "n", "F(n)", "GCD", "Time(us)", "Memory(KB)");
    printf("------------------------------------------------------------\n");

    for (int n = 5; n <= 40; n++) { 
        struct rusage usage;
        clock_t start_time = clock();

        unsigned long long fn = fibonacci(n);
        unsigned long long fn_minus_1 = fibonacci(n - 1);
        
        unsigned long long result_gcd = gcd(fn, fn_minus_1);

        clock_t end_time = clock();
        getrusage(RUSAGE_SELF, &usage);

        double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000000;

        printf("%-5d | %-12llu | %-5llu | %-12.2f | %-10ld\n", 
                n, fn, result_gcd, elapsed_time, usage.ru_maxrss);
        
        if (n % 5 == 0) fflush(stdout);
    }

    return 0;
}