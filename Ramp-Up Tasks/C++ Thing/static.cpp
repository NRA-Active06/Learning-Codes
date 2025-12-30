#include <iostream>
//Storage Classes - Scope / Linkage
// By default the variables local to functions are auto storage class variables
//scope - local, linkage - local, storage - stack
//static local variable - scope: local, linkage:local, storage - static part of heap
//non static global variable - global scope, external linkage, storage - static part of heap
//static global variable - file scope, internal linkage, storage - startic part of heap

int external_i = 20;
static int file_scope_i = 30;

void testStatic() {
    static int i = 10;
    file_scope_i = 40;
    int j = 10;
    i++;
    j++;
    std::cout << "This is i: " << i << "/nThis is j: " << j << std::endl;
}


int main() {
    extern void accessing_external_i();
    file_scope_i = 50;
    testStatic();
    testStatic();
    testStatic();
    testStatic();
    testStatic();
    
    std::cout <<" External I "<< external_i<<std::endl;
    accessing_external_i();
    std::cout <<" External I "<< external_i<<std::endl;
    
    return 0;
}