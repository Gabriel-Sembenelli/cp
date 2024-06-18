/*
MaxHeap
Reference: https://csacademy.com/lesson/heaps

O(lgN) push, pop and change
O(1) peek top element
*/

using T = int;
using Heap = vector<T>;

int bubbleUp(Heap &H, int index){
    while(index){
        int dad = (index + 1) / 2 - 1;
        if(H[index] > H[dad]){
            swap(H[index], H[dad]);
            index = dad;
        }else break;
    }
    return index;
}

int bubbleDown(Heap &H, int index){
    int sz = size(H);
    while(2 * index + 1 < sz){
        int child = 2 * index + 1;
        if(child + 1 < sz and H[child+1] > H[child])
            ++child;
        if(H[child] > H[index]){
            swap(H[child], H[index]);
            index = child;
        }else break;
    }
    return index;
}

T top(Heap &H){ return H[0]; }

int push(Heap &H, T x){
    H.push_back(x);
    return bubbleUp(H, signed(size(H)) - 1);
}

T pop(Heap &H){
    T key = H[0];
    swap(H[0], H.back());
    H.pop_back();
    bubbleDown(H, 0);
    return key;
}

int change(Heap &H, int index, T val){
    if(val > H[index]){
        H[index] = val;
        return bubbleUp(H, index);
    }
    H[index] = val;
    return bubbleDown(H, index);
}

void print(Heap &H, int index = 0){
    int sz = size(H);
    int child = 2 * index + 1;
    cout << "(";
    if(child < sz) print(H, child);
    if(index < sz) cout << H[index];
    if(child+1 < sz) print(H, child+1);
    cout << ")";
    if(index == 0) cout << '\n';
}