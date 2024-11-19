#include <stdio.h>
#include "calc_logic.h" 
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Hàm chuyển đổi alphanumeric sang số thực
double alphanumericToNumeric(const char* input) {
    double result = 0;
    int i = 0;
    
    // Nếu ký tự đầu tiên là chữ cái
    char ch = input[0];

    if (isalpha(ch)) {
        if (isupper(ch)) {
            // Nếu là chữ hoa, giá trị bắt đầu từ 10
            result = ch - 'A' + 10;
        } else if (islower(ch)) {
            // Nếu là chữ thường, giá trị bắt đầu từ 36
            result = ch - 'a' + 36;
        }
        i = 1;  // Tiến tới ký tự tiếp theo
    }

    // Xử lý các ký tự còn lại nếu là số
    while (input[i] != '\0') {
        if (isdigit(input[i])) {
            result = result * 10 + (input[i] - '0');
        } else {
            // Nếu gặp ký tự không phải số, trả về lỗi
            return -1;
        }
        i++;
    }

    return result;
}


// Định nghĩa các hàm toán học
double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    if (num2 != 0) {
        return num1 / num2;
    } else {
        printf("MATH ERROR: Division by zero.\n");
        return -1;  // Trả về lỗi nếu chia cho 0
    }
}
