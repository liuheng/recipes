//In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending order of size from top to bottom (e.g., each disk sits on top of an even larger one). You have the following constraints: (A) Only one disk can be moved at a time. (B) A disk is slid off the top of one rod onto the next rod. © A disk can only be placed on top of a larger disk. Write a program to move the disks from the first rod to the last using Stacks.

#include <iostream>

using namespace std;

// the recursion version

void moveOne(int N, int from, int to) {
    cout<<"move "<<N<<" from "<<from<<" to "<<to<<endl;
}

void Hanoi(int N, int from, int to, int temp) {
    if (N == 1) {
        moveOne(N, from, to);
    } else {
        Hanoi(N-1, from, temp, to);
        moveOne(N, from, to);
        Hanoi(N-1, temp, to, from);
    }
}

int main() {
    Hanoi(5, 1, 3, 2);
    return 0;
}
