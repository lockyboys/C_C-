/*
    파일의 사용의 필요성과 파일 종류
    ● 파일의 필요성
        - 프로로그램이 종료되더라도 디스크에 내용을 남길 수 있다
    ● 파일의 두가지 종류
        - 텍스트 파일(*.txt)
            ．내용이 눈에 보이는 코드 영역의 문자 들로만 이루어진 파일
            ．테스트 편집기를 통하여 그 내용을 보고 수정 가능
        - 이진 파일(BINARY FILE)
            ．코드 영역의 제한 없이 모든 내용을 저장하는 파일(실행파일, 그림 파일, 음악 파일, 동영상 파일 등)
            ．전용 프로그램으로써 내용을 볼 수 있음

    파일위치(파일 경로)
    ● 절대 경로 
        -실해 위치와 상관없이 위치 지정 가능
         "드라이브명:\\디렉터리명1\\디렉터리명\\파일명.txt"
         "c:\\Temp\\myfile.txt"
    ● 상대 경로
        - 경로 표시 헚이 파일 이름만 제골("myfile.txt")
        - 현재 프로그램이 수행되고 있는 위치에서 찾음
    fopen(() -> read/write -> fclose()
 1회(열기모드적용)   N회         1회
                fprintf/fscanf  (텍스트 파일용)
                fwrite/fread    (이진파일용)
                fputs/fgets     (텍스트 파일용)
   파일 열기 모드           문자열
   w  b                    "wb"
   a+ t                    "r+b"
   r                       "a+b
*/
#include <stdio.h>

void main() {
    char filename[] = "test.txt";
    FILE* fp;

    //fp = fopen(filename, "wb");
    //fp = fopen(filename, "ab");
    fp = fopen(filename, "r+b");
    if(fp == NULL){
        printf("%s 파일을 열 수 없습니다\n", filename);
        return;
    }
    fprintf(fp, "덧쓰기\n");
    /*for (int i = 0; i < 5; i++) {
        fprintf(fp, "문자열\n");
    }*/

    fclose(fp);
}