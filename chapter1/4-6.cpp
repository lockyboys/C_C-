#include <iostream>

using std::cout;
using std::endl;
using std::cin;

# pragma warning(disable:4996)
int* realloc(int* oldM, int oldSize, int newSize ) {
    //새집 구입
    int *newM = new int[newSize];

    //이사
    for (int i = 0; i < oldSize; i++) {
        newM[i] = oldM[i];
    }
    //기존집 해제
    delete[] oldM;

    return newM;    //새로운 집의 주소 리턴
}

int main() {
    int* arr = new int[3];

    arr[0] = 3;
    arr[1] = 4;
    arr[2] = 5;
    
    arr = realloc(arr, 3, 10);

    arr[3] = 6;
    arr[4] = 7;
    arr[5] = 8;

    for(int i = 0; i < 6; i++)
        cout << arr[i] << ' ';

    delete[] arr;

    return 0;

}
/*
#include <iostream>

using std::cout;
using std::endl;

int main() {

    // 처음 크기 3
    int* arr = new int[3];

    arr[0] = 3;
    arr[1] = 4;
    arr[2] = 5;

    // 크기 10으로 확장
    int* temp = new int[10];

    // 기존 값 복사
    for (int i = 0; i < 3; i++) {
        temp[i] = arr[i];
    }

    // 기존 메모리 해제
    delete[] arr;

    // 새 메모리 연결
    arr = temp;

    // 추가 데이터 저장
    arr[3] = 6;
    arr[4] = 6;
    arr[5] = 6;

    // 출력
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << ' ';
    }

    cout << endl;

    // 메모리 해제
    delete[] arr;

    return 0;
}
*/
/*
#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> arr;

    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    arr.push_back(6);
    arr.push_back(6);
    arr.push_back(6);

    for (int v : arr)
        cout << v << ' ';

    return 0;
}
*/