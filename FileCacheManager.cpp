//
// Created by davidregev on 31/12/18.
//

#include <fstream>
#include "FileCacheManager.h"


FileCacheManager::FileCacheManager(string fileName){
    string problem, solution;
    myFileName=fileName;
    ifstream myfile(fileName);
    if (myfile.is_open()) {
        while (getline(myfile, problem)) {
            if( getline(myfile, solution)){
                problemSolutionMap[problem]=solution;
            }else{
                throw invalid_argument("invalid number of line in file");
            }
        }
        myfile.close();
    }
}
bool FileCacheManager:: isExist(string p){
    map<string, string>::iterator it = problemSolutionMap.find(p);
    return it != problemSolutionMap.end();
}
 void FileCacheManager:: pushSolution(string p, string s){
     problemSolutionMap[p]=s;
     ofstream myfile;
     myfile.open(myFileName,std::ios::app);
     if (myfile.is_open()) {
         myfile << p+"\n"+s+"\n";
     }else{
         throw invalid_argument("not good file");
     }
     myfile.close();

}
 string FileCacheManager :: popSolution(string p){
     if(isExist(p)) {
         return  problemSolutionMap[p];
     }else{
         throw invalid_argument("try to get a solution to a problem that not exist in the cache");
     }
}