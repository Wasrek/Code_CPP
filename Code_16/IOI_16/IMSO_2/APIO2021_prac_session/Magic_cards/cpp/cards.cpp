#include "cards.h"
#include<bits/stdc++.h>
// #include "stub.cpp"
using namespace std;
int n,k;
void init_magician(int N, int K) {
  n=N; k=K;
}

void init_assistant(int N, int K) {
  n=N; k=K;
}

std::vector<int> sub1_choose(std::vector<int> cards) {
  vector<int> temp;
  if(cards[0]==1 && cards[1]==2){
    temp.push_back(1);
    return temp;
  }
  if(cards[0]==1 && cards[1]==3){
    temp.push_back(3);
    return temp;
  }
  if(cards[0]==2 && cards[1]==3){
    temp.push_back(2);
    return temp;
  }
  return temp;
}

std::vector<int> sub2_choose(std::vector<int> cards) {
  if(cards[2]==cards[1]+1){
    cards.erase(cards.begin()+2);
  }else if(cards[2]==cards[1]+2){
    cards.erase(cards.begin()+2);
    swap(cards[0],cards[1]);
  }else{
    cards.erase(cards.begin());
  }
  return cards;
}

std::vector<int> bigsub_choose(std::vector<int> cards) {
  int mi=cards[0],era=-1;
  for(int i=1;i<cards.size();i++){
    if(cards[i]%2!=mi%2){
      era=cards[i];
      cards.erase(cards.begin()+i);
      break;
    }
  }
  if(era==-1){
    era=cards[0];
    cards.erase(cards.begin());
  }
  int diff=era/2;
  while(diff--){
    next_permutation(cards.begin(),cards.end());
  }
  return cards;
}

std::vector<int> choose_cards(std::vector<int> cards) {
  if(cards.size()==2) return sub1_choose(cards);
  else if(cards.size()==3) return sub2_choose(cards);
  else if(cards.size()>3) return bigsub_choose(cards);
}

int sub1_find_cards(std::vector<int> cards){
  if(cards[0]==1) return 2;
  else if(cards[0]==2) return 3;
  else if(cards[0]==3) return 1;
}

int sub2_find_cards(std::vector<int> cards){
  if(cards[1]==5) return 1; 
  if(cards[0]<cards[1]){
    return cards[1]+1;
  }else return cards[0]+2;
}

int bigsub_find_card(std::vector<int> cards) { 
  vector<int> temp;
  temp=cards;
  int k=0;
  sort(temp.begin(),temp.end());
  int mi=temp[0];
  int ch=(temp[0]%2)^1;
  while(temp!=cards){
    k++;
    next_permutation(temp.begin(),temp.end());
  }
  if(k*2+1<=mi){
    ch=temp[0]%2;
  }
  return k*2+ch;
}

int find_discarded_card(std::vector<int> cards) {
  if(cards.size()==1) return sub1_find_cards(cards);
  else if(cards.size()==2) return sub2_find_cards(cards);
  else if(cards.size()>3) return bigsub_find_card(cards);
}
/*
1000 8 3
2 3 5 7 9 11 13 15
1 3 5 7 9 11 13 15
2 4 6 8 10 12 14 16
*/