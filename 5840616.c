    #include <stdio.h>
    #include <stdint.h>

    int main() {

        int8_t val = -1;
        
        unsigned char *ptr = (unsigned char *)&val;

        printf("정수 -1의 메모리 값 (16진수): 0x%02X\n", *ptr);

        if (*ptr == 0xFF) {
            printf("결과: 현재 사용하고 있는 컴퓨터는 2의 보수 방식을 이용해 정수를 표현하고 있습니다.\n");
        } else if (*ptr == 0xFE) {
            printf("결과: 현재 사용하고 있는 컴퓨터는 1의 보수 방식을 이용해 정수를 표현하고 있습니다.\n");
        } else

        

        return 0;
    }