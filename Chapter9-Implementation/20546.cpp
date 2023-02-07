#include <bits/stdc++.h>
using namespace std;

int budget, temp;
vector<int> stockPrice;

int BNP() {
  int cash = budget;
  int stockCnt = 0;
  for(int i = 0; i < 14; i++) {
    // 구입한 주식 수
    int stockBought = cash / stockPrice[i];
    // 주식을 살 수 있는 경우
    if(stockBought > 0) {
      stockCnt += stockBought;
      cash -= (stockBought * stockPrice[i]);
    }
  }
  
  return cash + (stockCnt * stockPrice[13]);
}

int TIMING() {
  int cash = budget;
  int stockCnt = 0;
  int gainStreak = 0; // 주가가 전일 대비 연속적으로 상승한 일 수
  int sinkStreak = 0; // 주가가 전일 대비 연속적으로 하락한 일 수

  for(int i = 1; i < 14; i++) {
    // 전일 대비 주가 상승
    if(stockPrice[i-1] < stockPrice[i]) {
      gainStreak++;
      sinkStreak = 0;
    }
    // 전일 대비 주가 하락
    if(stockPrice[i-1] > stockPrice[i]) {
      sinkStreak++;
      gainStreak = 0;
    }
    // 전일과 오늘의 주가가 동일. 상승 일 수와 하락 일 수 초기화
    if(stockPrice[i-1] == stockPrice[i]) {
      gainStreak = 0;
      sinkStreak = 0;
    }

    // 3일 연속 상승. 전량 매도
    if(gainStreak >= 3) {
      cash += stockCnt * stockPrice[i];
      stockCnt = 0;
    }
    // 3일 연속 하락. 전량 매수
    if(sinkStreak >= 3) {
      int stockBought = cash / stockPrice[i];

      if(stockBought > 0) {
      stockCnt += stockBought;
      cash -= (stockBought * stockPrice[i]);
      }
    }
  }
  
  return cash + (stockCnt * stockPrice[13]); 
}

int main() {
  cin >> budget;
  for(int i = 0; i < 14; i++) {
    cin >> temp;
    stockPrice.push_back(temp);
  }

  int bnp = BNP();
  int timing = TIMING();

  if(bnp == timing) {
    cout << "SAMESAME";
  } else if(bnp > timing) {
    cout << "BNP";
  } else {
    cout << "TIMING";
  }

}