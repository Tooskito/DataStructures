
#include <cstdlib>
#include <iostream>
class Pascal {
    int length, height;
    int* data;
public:
    Pascal(int heightIn) : height(heightIn) {
        length = int( (double)height / 2 * (1 + height) );
        data = (int*)malloc(sizeof(int) * length);
        if (not data)
            exit(EXIT_FAILURE);
        initializeTriangle();
    }

    ~Pascal() {
        free(data);
    }

    void initializeTriangle() {
        // If height was zero.
        if (not height)
            return;
        data[0] = 1;
        std::cout << 1 << std::endl;

        int prevRowStart = 0;
        int currRowStart = 1;
        // curr - prev = last row len
        // curr row len = curr - prev + 1
        // if i >= currRowStart + currRowStart - prev + 1
        // then move prevRowstart and currowstart
        for (int dataIndex = 1; dataIndex < height + 1; ++dataIndex) {
            int currIndex = dataIndex - currRowStart;
            int prevRowLen = currRowStart - prevRowStart;
            int currRowLen = prevRowLen + 1;
            // Store values.
            if (currIndex == 0 || currIndex == currRowLen)
                data[dataIndex] = 1;
            else
                data[dataIndex] = data[prevRowStart + currIndex - 1] + data[prevRowStart + currIndex];
            std::cout << data[dataIndex] << " ";
            // Move forward.
            if (dataIndex >= currRowStart + currRowLen) {
                std::cout << std::endl;
                prevRowLen = currRowLen;
                currRowLen = currRowLen + 1;
            }
        }

    }
};
int main() {
    Pascal p(7);
}