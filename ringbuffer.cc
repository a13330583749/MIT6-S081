#include <iostream>
#include <string.h>
#define SIZE 16

void print_buffer(char* pb, int i)
{
    for(int j=0; j<i&&j<SIZE; j++){
        std::cout << pb[j] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    char *pbead = new char[SIZE];
    char *ptail = pbead + sizeof(char) * SIZE;
    memset(pbead, 0, sizeof(char) * SIZE);
    char input;
    int i = 0;
    while (1)
    {
        std::cin >> input;
        switch (input)
        {
        case 'R':
            std::cout << "输出为：" << std::endl;
            print_buffer(pbead, i);
            delete [] pbead;
            pbead = nullptr;
            return 0;
            break;
        case 'Q':
            std::cout << "退出运行" << std::endl;
            // print_buffer(pbead);
            delete [] pbead;
            pbead = nullptr;
            return 0;
            break;   
        default:
            pbead[i%SIZE] = input;
            if(i%SIZE == SIZE - 1)
                std::cout << "a circle\n";
            i++;
            break;
        }
    }
    delete[] pbead;
    pbead = nullptr;
    return 0;
}