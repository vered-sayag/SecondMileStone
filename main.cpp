#include <iostream>
#include "FileCacheManager.h"
int main() {

    FileCacheManager fileCacheManager("test.txt");
    if(!fileCacheManager.isExist("the anser of the universe")){
        fileCacheManager.pushSolution("the anser of the universe","42");
    }else
    {
      cout<<fileCacheManager.popSolution("the anser of the universe") <<endl;
    }
    return 0;
}