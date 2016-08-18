#include <iostream>
#include <vector>

typedef std::vector< std::vector<int> > Matrix;

void VoidMatrix(Matrix* matrix) {
    const size_t N = matrix->size();
    const size_t M = (&(*matrix)[0])->size();
    if(N<=1||M<=1){
        return;
    }
    bool row[N], col[M];
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));

    for(size_t i = 0; i < N;i++){
        if (!row[i]) {
            for (size_t j = 0; j < M; j++) {
                if (!col[j]) {
                    if ((*matrix)[i][j]==0) {
                        row[i]=true;
                        col[j]=true;
                    }
                }
            }
        }
    }
    for (size_t i=0; i<N; i++) {
        for (size_t j=0; j<M; j++){
            if(row[i] || col[j])
                (*matrix)[i][j] = 0;
            }
        }
}

void PrintMatrix(Matrix* matrix) {
    const size_t N = matrix->size();
    const size_t M = (&(*matrix)[0])->size();
    for(size_t i = 0; i < N;i++){
        for (size_t j = 0; j < M; j++) {
            printf("%d ", (*matrix)[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int arr_a[] = {1, 0, 3, 4};
    std::vector<int> a (arr_a, arr_a + sizeof(arr_a) / sizeof(int));
    int arr_b[] = {4, 5, 0, 8};
    std::vector<int> b (arr_b, arr_b + sizeof(arr_b) / sizeof(int));
    int arr_c[] = {9, 10, 0, 12};
    std::vector<int> c (arr_c, arr_c + sizeof(arr_c) / sizeof(int));
    int arr_d[] = {13, 14, 15, 16};
    std::vector<int> d (arr_d, arr_d + sizeof(arr_d) / sizeof(int));
    
    Matrix m;
    m.push_back(a);
    m.push_back(b);
    m.push_back(c);
    m.push_back(d);
    
    PrintMatrix(&m);
    
    VoidMatrix(&m);
    
    PrintMatrix(&m);
}