//Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees.
//Can you do this in place?

#include <cassert>
#include <cstring>

using namespace std;

void swap(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

//rotate left the matrix
void rotateLeft(int *a, int N) {
    for (int i=0; i<N; ++i) {
        for (int j=i+1; j<N; ++j) {
            swap(*(a+i*N+j), *(a+j*N+i));
        }
    }
    for (int k=0; k<=N/2; ++k) {
        for (int l=0; l<N; ++l) {
            swap(*(a+k*N+l), *(a+(N-k-1)*N+l));
        }
    }
}

int main() {
    int a[25] = {0};
    for (int i=0; i<25; ++i) {
        a[i] = i+1;
    }
    rotateLeft(a, 5);
    int b[25] = {5,10,15,20,25,4,9,14,19,24,3,8,13,18,23,2,7,12,17,22,1,6,11,16,21};
    assert(memcmp(a, b, 25) == 0);
}
