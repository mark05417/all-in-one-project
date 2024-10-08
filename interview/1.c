#include <stdio.h>
#include <stdlib.h>

// 將時間轉換為以秒表示
int time_to_seconds(int time) {
    int hours = time / 10000;
    int minutes = (time / 100) % 100;
    int seconds = time % 100;
    return hours * 3600 + minutes * 60 + seconds;
}

int main() {
    int time1, time2;
    
    // 輸入兩個時間
    printf("請輸入第一個時間 (HHMMSS): ");
    scanf("%d", &time1);
    
    printf("請輸入第二個時間 (HHMMSS): ");
    scanf("%d", &time2);

    // 將時間轉換為秒
    int seconds1 = time_to_seconds(time1);
    int seconds2 = time_to_seconds(time2);
    
    // 計算時間差並取絕對值
    int time_diff = abs(seconds2 - seconds1);

    // 輸出時間差
    printf("時間差是 %d 秒。\n", time_diff);
    
    return 0;
}
