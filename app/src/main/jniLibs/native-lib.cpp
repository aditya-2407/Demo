// native-lib.cpp
#include <jni.h>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_anujdemo_MainActivity_transposeMatrix(JNIEnv* env, jobject /* this */) {
    std::ifstream file("./matrix.txt");
    std::vector<std::vector<int>> matrix(100, std::vector<int>(100));
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            file >> matrix[i][j];
        }
    }
    file.close();

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<int>> transposedMatrix(100, std::vector<int>(100));
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    return env->NewStringUTF(std::to_string(duration).c_str());
}