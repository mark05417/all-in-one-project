#include <cuda_runtime.h>
#include <iostream>

// 每個 CUDA kernel 的執行函數
__global__ void vectorAdd(const float *A, const float *B, float *C, int N) {
    int i = blockIdx.x * blockDim.x + threadIdx.x; // 計算線程的全域索引
    if (i < N) {
        C[i] = A[i] + B[i];
    }
}

int main() {
    int N = 1 << 20; // 向量大小（1M 元素）
    size_t size = N * sizeof(float);

    // 分配主機記憶體
    float *h_A = (float *)malloc(size);
    float *h_B = (float *)malloc(size);
    float *h_C = (float *)malloc(size);

    // 初始化主機記憶體
    for (int i = 0; i < N; i++) {
        h_A[i] = i * 0.5f;
        h_B[i] = i * 2.0f;
    }

    // 分配裝置記憶體
    float *d_A, *d_B, *d_C;
    cudaMalloc((void **)&d_A, size);
    cudaMalloc((void **)&d_B, size);
    cudaMalloc((void **)&d_C, size);

    // 將資料從主機傳輸到裝置
    cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);

    // 定義 block 和 grid 大小
    int threadsPerBlock = 256;
    int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;

    // 執行 CUDA kernel
    vectorAdd<<<blocksPerGrid, threadsPerBlock>>>(d_A, d_B, d_C, N);

    // 將結果從裝置傳輸回主機
    cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);

    // 驗證結果
    for (int i = 0; i < 10; i++) {
        std::cout << "C[" << i << "] = " << h_C[i] << std::endl;
    }

    // 清理資源
    free(h_A);
    free(h_B);
    free(h_C);
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return 0;
}
