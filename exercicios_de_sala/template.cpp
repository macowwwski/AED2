#include <iostream>

template<typename T>
void trocar(T &a, T &b){
    T t = a;
    a = b;
    b = t;
}

int main(){
    int x = 10;
    int y = 5;
    float f1 = 4.5;
    float f2 = 3.2;

    trocar(x, y);
    trocar(f1, f2);

    std::cout << x << " " << y << "\n";
    std::cout << f1 << " " << f2 << "\n";

    return 0;
}