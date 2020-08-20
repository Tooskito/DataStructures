
#include <cstdlib>
#include <iostream>
class Pascal {
    int length, height;
    int* data;
public:
    Pascal(int heightIn) : height(heightIn) {
        length = height * (height + 1) / 2;
        data = (int*)malloc(sizeof(int) * length);
        if (not data)
            exit(EXIT_FAILURE);
        std::cout << "Pascal(" << height << ") with length " << length << std::endl;
        initializeTriangle();
    }

    ~Pascal() {
        free(data);
    }

    void initializeTriangle() {
        // If height was zero.
        data[0] = 1;

        int prevRowStart = 0;
        int currRowStart = 1;
        for (int dataIndex = 1; dataIndex < length; ++dataIndex) {
            int prevRowLen = currRowStart - prevRowStart;
            int currRowLen = prevRowLen + 1;
            
            if (dataIndex == currRowStart) {
                data[dataIndex] = 1;
            }
            else if (dataIndex == currRowStart + currRowLen - 1) {
                data[dataIndex] = 1;
                prevRowStart = currRowStart;
                currRowStart = dataIndex + 1;
            }
            else {
                data[dataIndex] = data[dataIndex - currRowLen] + data[dataIndex - prevRowLen];
            }
        }
    }

    friend std::ostream& operator<< (std::ostream& os, const Pascal& p) {
        int currHeight = 1;
        int leftInRow = 1;
        for (int dataIndex = 0; dataIndex < p.length; ++dataIndex) {
            os << p.data[dataIndex] << " ";
            leftInRow -= 1;
            if (not leftInRow) {
                os << std::endl;
                currHeight += 1;
                leftInRow = currHeight;
            }
        }
        return os;
    }
};
int main() {
    Pascal p(20);
    std::cout << p << std::endl;
}