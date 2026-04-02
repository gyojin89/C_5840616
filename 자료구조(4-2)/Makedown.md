### <과제 코드>

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

<img width="436" height="547" alt="스크린샷 2026-04-02 오후 2 52 27" src="https://github.com/user-attachments/assets/c45e05e4-9e5a-439f-af1d-41114573a29f" />

위 결과를 바탕으로 한 GCD의 시간복잡도 및 피보나치 수열의 시간복잡도
### 1. GCD의 시간복잡도
- 최대공약수(GCD)를 계산하는 일반적인 알고리즘인 유클리드 알고리즘(Euclidean Algorithm)의 시간복잡도는 O(log⁡(min⁡(a,b)))O(\log(\min(a, b)))O(log(min(a,b)))
- 주어진 데이터에서 매 번 GCD는 1로 고정되어 있으며, 매우 빠르게 계산되므로 GCD 계산 시간은 매우 작은 값으로 나옴

### 2. 피보나치 수열의 시간복잡도
- 재귀적인 방식으로 구현 시 피보나치 수열의 계산 시간복잡도는 O(2의 n승)
- n이 증가함에 따라 소요 시간은 기하급수적으로 증가하는 것을 확인 가능

### 3. Big-O 계산식 요약
- 피보나치 수열: O(2^n) (재귀) => O(n) (동적 프로그래밍)
- GCD: O(log(min(F(n), F(n-1)))) = O(1) (F(n)과 F(n-1)의 GCD는 항상 1)




  
