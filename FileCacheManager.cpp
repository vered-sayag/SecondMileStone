//
// Created by davidregev on 31/12/18.
//

#include <fstream>
#include "FileCacheManager.h"


server_side::FileCacheManager::FileCacheManager(string fileName){
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
bool server_side::FileCacheManager:: isExist(string p){
    pthread_mutex_lock(&mutex);
    map<string, string>::iterator it = problemSolutionMap.find(p);
    pthread_mutex_unlock(&mutex);
    return it != problemSolutionMap.end();

}
 void server_side::FileCacheManager:: pushSolution(string p, string s){
     pthread_mutex_lock(&mutex);
    problemSolutionMap[p]=s;
     ofstream myfile;
     myfile.open(myFileName,std::ios::app);
     if (myfile.is_open()) {
         myfile << p+"\n"+s+"\n";
     }else{
         throw invalid_argument("not good file");
     }
     myfile.close();
     pthread_mutex_unlock(&mutex);

}
 string server_side::FileCacheManager :: popSolution(string p){
    if(isExist(p)) {
         return  problemSolutionMap[p];
     }else{
         throw invalid_argument("try to get a solution to a problem that not exist in the cache");
     }


}