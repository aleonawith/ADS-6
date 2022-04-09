// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    int first, last, count;
    T arr[size] = {0};
 public:
    TPQueue() : first(0), last(0), count(0) {}
    void push(T temp) {
      if (!isFull()) {
        int t = last++;
        if (count == 0) {
          arr[t] = temp;
        } else {
          while (--t >= first && arr[t % size].prior < temp.prior) {
            arr[(t + 1) % size] = arr[t % size];
          }
          arr[(t + 1) % size] = temp;
        }
        count++;
      } else {
        throw "Full!";
      }
    }
    T pop() {
      return arr[(first++) % size];
    }
    bool isFull() const {
      return count == size;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
