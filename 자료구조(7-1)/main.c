#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    int id;
    int score;
} Student;

int main() {
    int N;
    char nameList[100][50]; 
    int nameCount = 0;

    srand((unsigned int)time(NULL));

    FILE *fp = fopen("name_list.txt", "r");
    if (fp == NULL) {
        printf("이름 파일을 열 수 없습니다.\n");
        return 1;
    }

    char file_buff[50];

while (nameCount < 100 && fgets(file_buff, sizeof(file_buff), fp) != NULL) {

    file_buff[strcspn(file_buff, "\r\n")] = '\0';

    strcpy(nameList[nameCount], file_buff);
    nameCount++;

    memset(file_buff, 0, sizeof(file_buff));
}

    if (nameCount == 0) {
        printf("이름 데이터가 없습니다.\n");
        return 1;
    }

    printf("학생 수 N을 입력하세요: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("잘못된 입력입니다.\n");
        return 1;
    }

    Student *students = (Student *)malloc(sizeof(Student) * N);
    if (students == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        int nameIdx = rand() % nameCount;

        strcpy(students[i].name, nameList[nameIdx]);
        students[i].id = i + 1;                     
        students[i].score = (rand() % 100) + 1;     
    }

    int maxIdx = 0, minIdx = 0;
    double sum = 0;

    for (int i = 0; i < N; i++) {
        sum += students[i].score;

        if (students[i].score > students[maxIdx].score) {
            maxIdx = i;
        }
        if (students[i].score < students[minIdx].score) {
            minIdx = i;
        }
    }

    printf("\n--- 생성된 학생 정보 ---\n");
    for (int i = 0; i < N; i++) {
        printf("학번: %d, 이름: %s, 성적: %d\n",
               students[i].id, students[i].name, students[i].score);
    }

    printf("\n--- 통계 결과 ---\n");
    printf("최고점 학생: %s (학번: %d, 점수: %d)\n",
           students[maxIdx].name, students[maxIdx].id, students[maxIdx].score);

    printf("최저점 학생: %s (학번: %d, 점수: %d)\n",
           students[minIdx].name, students[minIdx].id, students[minIdx].score);

    printf("전체 평균: %.2f\n", (double)sum / N);

    free(students);

    return 0;
}