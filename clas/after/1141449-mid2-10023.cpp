// Compute the square root of a huge integer.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;
using std::setfill;

#include <cstring>
#include <cmath>

// put the square root of hugeInt into the array squareRoot
void compSquareRoot(long long int* hugeInt, long long int* squareRoot, int hugeIntSize, int sqrtSize);

// put the square of hugeInt into the array square
void compSquare(long long int* hugeInt, long long int* square, int hugeIntSize, int& squareSize);

// if hugeInt1 == hugeInt2, return true; otherwise, return false
bool equal(long long int* hugeInt1, long long int* hugeInt2, int size1, int size2);

// if hugeInt1 < hugeInt2, return true; otherwise, return false
bool less(long long int* hugeInt1, long long int* hugeInt2, int size1, int size2);

const int arraySize = 1010;

int main()
{
    int testCase;
    cin >> testCase;
    for (int i = 1; i <= testCase; i++)
    {
        char str[arraySize] = {};
        cin >> str;

        size_t numDigits = strlen(str);
        if (numDigits < 10)
            cout << sqrt(atoi(str)) << endl;
        else
        {
            int* digits = new int[numDigits + 3]();
            for (size_t j = 0; j < numDigits; ++j)
                digits[j] = static_cast<int>(str[numDigits - 1 - j]) - '0';

            size_t last = (numDigits - 1) / 4;
            size_t hugeIntSize = last + 1;
            long long int* hugeInt = new long long int[hugeIntSize]();
            for (size_t j = 0; j <= last; j++)
                hugeInt[j] = digits[4 * j] +
                digits[4 * j + 1] * 10 +
                digits[4 * j + 2] * 100 +
                digits[4 * j + 3] * 1000;
            size_t sqrtSize = (hugeIntSize + 1) / 2; // the number of digits of squareRoot is sqrtSize
            long long int* squareRoot = new long long int[sqrtSize](); // the square root of hugeInt

            // put the square root of hugeInt into the array squareRoot
            compSquareRoot(hugeInt, squareRoot, hugeIntSize, sqrtSize);

            cout << squareRoot[sqrtSize - 1];
            for (int j = sqrtSize - 2; j >= 0; j--)
                cout << setw(4) << setfill('0') << squareRoot[j];
            cout << endl;

            delete[] squareRoot;
            delete[] hugeInt;
            delete[] digits;
        }

        if (i < testCase)
            cout << endl;
    }

    system("pause");
}

// put the square root of hugeInt into the array squareRoot
void compSquareRoot(long long int* hugeInt, long long int* squareRoot, int hugeIntSize, int sqrtSize)
{
    int squareSize = hugeIntSize;
    long long int* square = new long long int[squareSize]();
    int low = 0, high = 9999;
    int middle;
    for (int i = 0; i < sqrtSize; i++){
        squareRoot[i] = 0;
    }
    for (int i = sqrtSize - 1; i >= 0; i--) {
        low = 0;                                            //added
        high = 9999;                                        //added
        while (low <= high) {
            middle = (low + high) / 2;                      //modified
            squareRoot[i] = middle;
            compSquare(squareRoot, square, sqrtSize, squareSize);
            if (less(square, hugeInt, squareSize, hugeIntSize)) {
                low = middle + 1;
            }
            else if (equal(square, hugeInt, squareSize, hugeIntSize)) {
                //squareRoot = square;                      //deleted
                break;
            }
            else {
                high = middle - 1;
            }
        }
        if ((!less(square, hugeInt, squareSize, hugeIntSize))&&(!equal(square, hugeInt, squareSize, hugeIntSize))) {
            middle--;
            squareRoot[i] = middle;
            compSquare(squareRoot, square, sqrtSize, squareSize);
        }
    }
    delete[] square;
}

// put the square of hugeInt into the array square
void compSquare(long long int* hugeInt, long long int* square, int hugeIntSize, int& squareSize)
{
    for (int i = 0; i < squareSize; i++) {
        square[i] = 0;
    }
    for (int i = 0; i < hugeIntSize; i++) {
        for (int j = 0; j < hugeIntSize; j++) {
            square[i + j] += hugeInt[i] * hugeInt[j];
        }
    }
    for (int i = 0; i < squareSize - 1; i++) {
        if (square[i] >= 10000) {
            square[i + 1] += square[i] / 10000;
            square[i] %= 10000;
        }
    }
}

// if hugeInt1 == hugeInt2, return true; otherwise, return false
bool equal(long long int* hugeInt1, long long int* hugeInt2, int size1, int size2)
{
    if (size1 != size2)
        return false;

    for (int i = size1 - 1; i >= 0; i--)
        if (hugeInt1[i] != hugeInt2[i])
            return false;

    return true;
}

// if hugeInt1 < hugeInt2, retuen true; otherwise, return false
bool less(long long int* hugeInt1, long long int* hugeInt2, int size1, int size2)
{
    if (size1 < size2)
        return true;
    if (size1 > size2)
        return false;

    for (int i = size1 - 1; i >= 0; i--)
    {
        if (hugeInt1[i] < hugeInt2[i])
            return true;
        if (hugeInt1[i] > hugeInt2[i])
            return false;
    }

    return false;
}